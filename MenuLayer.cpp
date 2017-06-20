// MenuLayer.cpp
#include "MenuLayer.h"
#include"GameLayer.h"
#include "ranklistScene.h"

void MenuLayer::menuCallback(Ref* pSender) {
	switch (((MenuItemImage *)pSender)->getTag()) {
	case 1:
		UserDefault::getInstance()->setFloatForKey("x",0);
		UserDefault::getInstance()->setFloatForKey("y", 0);
		UserDefault::getInstance()->setIntegerForKey("score", 0);
		UserDefault::getInstance()->setIntegerForKey("game", 1);
		UserDefault::getInstance()->setDoubleForKey("leftTime", 300);
		UserDefault::getInstance()->flush();
		toGameScene();
		
		break;
	case 2:
		toGameScene();
		break;
	case 3:
		toRanklistScene();
		break;
	case 4:
		Director::getInstance()->end();
		exit(0);
		break;
	default:
		break;
	}
}



void MenuLayer::toGameScene() {
	auto gameScene = GameLevelLayer::createScene();
	Director::getInstance()->replaceScene(gameScene);
}

void MenuLayer::toRanklistScene(){
    auto scene = ranklistScene::createScene();
    Director::getInstance()->replaceScene(scene);
}

bool MenuLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//create background
	auto background = Sprite::create("bg_opening.jpg");
	background->setScale(0.5);
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, 0);
	//create buttons
	auto startButton = MenuItemImage::create("button_start.png", "button_start_selected.png", CC_CALLBACK_1(MenuLayer::menuCallback, this));
	startButton->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.77));
	startButton->setScale(0.3);
	startButton->setTag(1);
	auto continueButton = MenuItemImage::create("button_continue.png", "button_continue_selected.png", CC_CALLBACK_1(MenuLayer::menuCallback, this));
	continueButton->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.65));
	continueButton->setScale(0.3);
	continueButton->setTag(2);
    	auto rankButton = MenuItemImage::create("button_rank.png", "button_rank_selected.png", CC_CALLBACK_1(MenuLayer::menuCallback, this));
    	rankButton->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.53));
    	rankButton->setScale(0.3);
    	rankButton->setTag(3);
	auto exitButton = MenuItemImage::create("button_exit.png", "button_exit_selected.png", CC_CALLBACK_1(MenuLayer::menuCallback, this));
	exitButton->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.41));
	exitButton->setScale(0.3);
	exitButton->setTag(4);
	//create menu
	auto menu = Menu::create(startButton, rankButton, continueButton, exitButton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 10);
	return true;
}



Scene* MenuLayer::createScene() {
	auto scene = Scene::create();
	auto layer = MenuLayer::create();
	scene->addChild(layer);
	return scene;
}
