#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <random>

using namespace geode::prelude;

class $modify(ClickPlayer, PlayerObject) {
    bool pushButton(PlayerButton btn) {
        // Hooking pushButton catches real clicks AND replay-bot playback,
        // since both end up calling it.
        if (btn == PlayerButton::Jump && PlayLayer::get()
            && Mod::get()->getSettingValue<bool>("enabled")) {
            // Only P1 so dual mode doesn't double the sound.
            if (!m_isSecondPlayer) {
                playClick();
            }
        }
        return PlayerObject::pushButton(btn);
    }

    void playClick() {
        static std::mt19937 rng{std::random_device{}()};

        auto mod = Mod::get();
        auto name = mod->getSettingValue<std::string>("click-sound");
        auto volume = static_cast<float>(mod->getSettingValue<double>("volume"));
        auto variation = mod->getSettingValue<double>("pitch-variation");

        float speed = 1.f;
        if (variation > 0.0) {
            std::uniform_real_distribution<double> dist(-variation, variation);
            speed = static_cast<float>(1.0 + dist(rng));
        }

        auto path = (mod->getResourcesDir() / fmt::format("{}.wav", name)).string();
        FMODAudioEngine::sharedEngine()->playEffect(path, speed, 0.f, volume);
    }
};
