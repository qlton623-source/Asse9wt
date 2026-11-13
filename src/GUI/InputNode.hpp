#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace qolmod {

    class InputNode : public TextInput {
    protected:
        bool initWithWidth(
            float width,
            std::string placeholder,
            ZStringView font
        );

        bool initWithSize(
            CCSize const& size,
            std::string placeholder,
            ZStringView font,
            bool multiline
        );

    public:
        static InputNode* create(
            float width,
            std::string placeholder,
            ZStringView font
        );

        static InputNode* create(
            CCSize const& size,
            std::string placeholder,
            ZStringView font
        );

        static InputNode* createMultiline(
            CCSize const& size,
            std::string placeholder,
            ZStringView font
        );

        void setLanguageFonts();
    };

}

class KeycodeNode : public CCNode {
protected:
    CCScale9Sprite* bg = nullptr;
    CCLabelBMFont* label = nullptr;
    int keycode = -1;

public:
    static KeycodeNode* create(int keycode);

    void setKeycode(int keycode);
    int getKeycode();

    virtual void setContentSize(const CCSize& contentSize);

    bool init(int keycode);
};