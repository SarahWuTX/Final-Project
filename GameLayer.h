#pragma once
#include"cocos2d.h"
#include"Player.h"
#include"MenuLayer.h"
#include"endingScene.h"
#include"SimpleAudioEngine.h"
#include"Monster.h"
#include"Unit.h"
using namespace CocosDenshion;


class GameLevelLayer : public cocos2d::CCLayer
{
public:
	GameLevelLayer(void) {};
	~GameLevelLayer(void) {};
	CREATE_FUNC(GameLevelLayer);
	static Scene* createScene();
	std::map<EventKeyboard::KeyCode, bool> keys;

	bool init();
	int screenWidth, screenHeight;
	Point origin;
	void onKeyPressed(EventKeyboard::KeyCode keycode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);
	void update(float delta);
	Player* _player;
	Monster* _monster;
	Unit*_unit;
	float scale;
	float X;
	float Y;
	bool isKeyPressed(EventKeyboard::KeyCode keycode);
	bool sound;
	void keyPressedDuration(EventKeyboard::KeyCode keycode, float delta);
	void smallWalkRight();
	void smallWalkLeft();
	void walkRight();
	void walkLeft();
	void setViewpointCenter(Vec2 positon);
	bool onContactBegin(PhysicsContact& contact);
	bool onContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve);
	void onContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve);
	void onContactSeparate(PhysicsContact& contact);
	Vec2 tileCoordForPosition(const Vec2& position);
	void updatewhenjump();
	void playerdie();
	void timer(float dt);
	void updateStart(float dt);
	void toEndingScene(float dt);
	void toMainScene();
	void toFinalPoint(float dt);
	void toNextGame(float dt);
	void menuCallBack(Ref* pSender);
	void toFlag();
	void enemyrun(Monster*szeName);
	void enemydie(Sprite*Name);
protected:
	cocos2d::CCTMXTiledMap *map;
	cocos2d::TMXLayer *Land;
	cocos2d::TMXLayer *Pipe;
	cocos2d::TMXLayer *Coin;
	cocos2d::TMXLayer *Block;
	cocos2d::TMXLayer *Flag;
	cocos2d::TMXLayer *Block_;
	cocos2d::TMXLayer *Pipe_;
	cocos2d::TMXLayer *Land_;
	float final;

private:
	time_t startTime;
	Label* timerLabel;
	MenuItemLabel* soundLabel;
	MenuItemLabel* saveLabel;
	Layer* timerLayer;
};
