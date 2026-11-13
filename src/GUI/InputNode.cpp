#include "InputNode.hpp"
#include "EasyBG.hpp"

#include <utility>

using namespace geode::prelude;
using namespace qolmod;


InputNode* InputNode::create(
    float width,
    std::string placeholder,
    ZStringView font
) {
    auto ret = new InputNode();

    if (ret->initWithWidth(width, std::move(placeholder), font)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}


InputNode* InputNode::create(
    CCSize const& size,
    std::string placeholder,
    ZStringView font
) {
    auto ret = new InputNode();

    if (ret->initWithSize(size, std::move(placeholder), font, false)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}


InputNode* InputNode::createMultiline(
    CCSize const& size,
    std::string placeholder,
    ZStringView font
) {
    auto ret = new InputNode();

    if (ret->initWithSize(size, std::move(placeholder), font, true)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}


bool InputNode::initWithWidth(
    float width,
    std::string placeholder,
    ZStringView font
) {
    if (!TextInput::init(width, placeholder, font))
        return false;

    hideBG();

    auto bg = EasyBG::create();

    if (!bg)
        return false;

    bg->setTargettingNode(this);
    bg->setAnchorPoint(ccp(0, 0));

    setTextAlign(TextInputAlign::Left);
    setFilter("");

    this->addChild(bg, -67);

    return true;
}


bool InputNode::initWithSize(
    CCSize const& size,
    std::string placeholder,
    ZStringView font,
    bool multiline
) {
    // Geode 6.0.0-alpha.1 TextInput only supports single-line inputs.
    // The width is preserved; multiline and custom height are not supported.

    (void)multiline;

    return initWithWidth(
        size.width,
        std::move(placeholder),
        font
    );
}


void InputNode::setLanguageFonts() {
    // Geode 6.0.0-alpha.1 does not expose the old
    // getContentLabel() and getPlaceholderLabel() methods.
}