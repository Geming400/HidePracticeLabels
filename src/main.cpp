#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>
class $modify(MyPlayLayer, PlayLayer) {
    void togglePracticeMode(bool practiceMode) {
        PlayLayer::togglePracticeMode(practiceMode);

        if (practiceMode && Mod::get()->getSettingValue<bool>("toggled")) {
            auto checkpointMenu = static_cast<CCMenu*>(m_uiLayer->getChildByID("checkpoint-menu"));
            checkpointMenu->setVisible(false);

            auto addCheckpointButton = static_cast<CCMenuItemSpriteExtra*>(checkpointMenu->getChildByID("add-checkpoint-button"));
            auto removeCheckpointButton = static_cast<CCMenuItemSpriteExtra*>(checkpointMenu->getChildByID("remove-checkpoint-button"));

            addCheckpointButton->setVisible(false);
            removeCheckpointButton->setVisible(false);
        }
    }

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        // Because I am way too lazy to test it, i'm making sure that i'll work because yes :3

        auto checkpointMenu = static_cast<CCMenu*>(m_uiLayer->getChildByID("checkpoint-menu"));
        checkpointMenu->setOpacity(0);

        static_cast<CCMenuItemSpriteExtra*>(checkpointMenu->getChildByID("add-checkpoint-button"))->setOpacity(0);
        static_cast<CCMenuItemSpriteExtra*>(checkpointMenu->getChildByID("remove-checkpoint-button"))->setOpacity(0);

        return true;
    }
};