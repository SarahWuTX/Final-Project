#include"gameLayer.h"
#include"Player.h"
USING_NS_CC;

CCScene* GameLevelLayer::scene()
{
	CCScene *scene = CCScene::create();
	if (!scene)
		return NULL;

	GameLevelLayer *layer = GameLevelLayer::create();

	scene->addChild(layer);

	return scene;
}

bool GameLevelLayer::init() {
	//加载一个蓝色背景当装饰
	CCLayerColor *blueSky = CCLayerColor::create(ccc4(100, 100, 250, 255));
	this->addChild(blueSky,1);
	//加载地图
	map = CCTMXTiledMap::create("level1.tmx");
	this->addChild(map,2);
	Player* _player = Player::create("koalio_stand.png");
	_player->setPosition(ccp(100, 200));
	map->addChild(_player, 15);
	_player->scheduleUpdate();
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//设定定时器，游戏时间5分钟
	auto timerLayer = Layer::create();
    	timerLabel = Label::create();
    	timerLabel->setTextColor(Color4B::WHITE);
    	timerLabel->setSystemFontSize(40);
    	timerLabel->setAnchorPoint(Vec2(0, 1));
    	timerLabel->setPosition(Vec2(20, visibleSize.height));
    	timerLayer->addChild(timerLabel);
    	startTime = time(NULL);
    	schedule(schedule_selector(GameLayer::timer));
	this->addChild(timerLayer, 100);
	return true;
}

void GameLayer:: timer(float dt){
    double usedTime_s = 300-difftime(time(NULL), startTime);
    if (usedTime_s>=0) {
        double usedTime_min = usedTime_s/60;
        timerLabel->setString(StringUtils::format("%02d:%02d", (int)usedTime_min,(int)(usedTime_s)%60));
    } else {
        unschedule(schedule_selector(GameLayer::timer));
        //执行游戏结束的函数
    }
}


