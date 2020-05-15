//
//  CJMTATrack.h
//  CJMTAFrameWork
//
//  Created by ChuJian on 2018/11/29.
//  Copyright © 2018年 ChuJian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CJMTATrack : NSObject
typedef void(^CJmtaXclient)(NSString *xClientEnable);
/**
 *  设置游戏平台
 */

+(void)gamePlatformId:(NSString *)gamePlatformId;


/**
 *  设置渠道ID
 */

+(void)gameChannelId:(NSString *)gameChannelId;


/**
 *  设置渠道名称
 */
+(void)gameChannelName:(NSString *)gameChannelName;

/**
 *  设置服务器ID
 */
+(void)gameServerId:(NSString *)gameServerId;


/**
 *  设置角色名称
 */

+(void)setRoleName:(NSString *)setRoleName;
/**
 *  设置角色ID
 */
+(void)setRoleId:(NSString *)setRoleId;

/**
 *  获取Clientaccesstoken
 */
+(void)sdkMtaXClientAccessToken:(NSString *)mtaCdnBaseUrl andClientAccessToken:(NSString *)mtaXClientAccessToken xClientCall:(CJmtaXclient)xClientBack;

+(void)sdkMtaSettingsTFStr:(NSString *)tfStr;


/**
 *  获取Useraccesstoken
 */

+(void)sdkMtaXUserAccessToken:(NSString *)mtaXUserAccessToken andMtaRefreshToken:(NSString *)mtaRefreshToken andMtaUserID:(NSString *)mtaUserID;

/**
 *  激活
 */
+(void)sdkActivatedEvent:(NSString *)apkn andAppn:(NSString *)appn andAppv:(NSString *)appv andSdkv:(NSString *)sdkv;

/**
 *  启动闪屏
 */
+(void)splashStartRequestedEvent:(NSString *)label andStatus:(NSString *)status;

/**
 *  访问资源服务器
 */
+(void)resourceServerVisitRequestedEvent:(NSString *)label andIp:(NSString *)ip andResourceId:(NSString *)resourceId;


/**
 *  版本检查
 */
+(void)appVersionCheckRequestedEvent:(NSString *)label andAppVer:(NSString *)appVer;


/**
 *  加载资源
 */
+(void)resourceLoadingRequestedEvent:(NSString *)label andResourceId:(NSString *)resourceId;

/**
 *  更新资源包
 */
+(void)resourceUpdateStartedEvent:(NSString *)label andResourceId:(NSString *)resourceId;


/**
 * 更新资源包结果
 */

+(void)resourceUpdatedEvent:(NSString *)label andResourceId:(NSString *)resourceId andStatus:(NSString *)status;

/**
 * SDK加载完毕
 */

+(void)sdkLoadedEvent:(NSString *)status;

/**
 * 注册界面调起请求
 */
+(void)registerPageDisplayRequestedEvent;

/**
 * 注册界面调起结果
 */
+(void)registerPageDisplayedEvent:(NSString *)status;

/**
 * 注册结果
 */
+(void)registeredEvent:(NSString *)registerAt andUserSource:(NSString *)userSource andUserID:(NSString *)userID;

/**
 * 登录界面调起
 */
+(void)loginPageDisplayRequestedEvent;

/**
 * 登录界面调起结果
 */
+(void)loginPageDisplayedEvent:(NSString *)status;

/**
 * 登录结果
 */
+(void)loggedinEvent:(NSString *)userSource andStatus:(NSString *)status;

/**
 * 公告调起结果
 */
+(void)noticePageDisplayedEvent:(NSString *)status;

/**
 * 区服加载请求结果
 */
+(void)gameServerListedEvent:(NSString *)label andStatus:(NSString *)status;

/**
 * 区服登录请求结果
 */
+(void)gameServerLoggedinEvent:(NSString *)label andStatus:(NSString *)status;


/**
 * 账号登出
 */

+(void)accountLogoutEvent;

/**
 * 游戏创角请求结果
 */

+(void)roleCreatedEvent:(NSString *)label andStatus:(NSString *)status;

/**
 * 角色登录请求
 */

+(void)roleLoginRequestedEvent:(NSString *)label;


/**
 * 角色登录请求结果
 */

+(void)roleLoggedinEvent:(NSString *)label andStatus:(NSString *)status;

/**
 * 角色登出
 */

+(void)roleLogoutEvent:(NSString *)label andStatus:(NSString *)status;

/**
 * 发起充值请求
 */

+(void)payRequestedEvent:(NSString *)orid andLevel:(NSString *)level andCurrency:(NSString *)currency;

/**
 * 充值界面调起
 */

+(void)payPageDisplayRequestedEvent;

/**
 * 充值界面调起结果
 */

+(void)payPageDisplayedEvent:(NSString *)status;

/**
 * 确认支付方式
 */

+(void)payMethodConfirmedEvent:(NSString *)payMethod andOrid:(NSString *)orid;

/**
 * 切换进入后台
 */

+(void)gameBackgroundSwitchedEvent:(NSString *)label;

/**
 * 切换进入前端
 */

+(void)gameForegroundSwitchedEvent:(NSString *)label;


/**
 * 自定义事件
 */

+(void)customizedEvent:(NSString *)label andCategory:(NSString *)category andCustomArray:(NSArray *)customarray;




/**
 * 加入公会
 */
+(void)gameUnionUserJoinedEventAndAfCustomerUserId:(NSString *)roleId;

/**
 * 任务变动
 */
+(void)gameTaskMovedEvent:(NSString *)gameTaskStr andAfCustomerUserId:(NSString *)roleId;

/**
 * 等级变化
 */
+(void)gameLevelChangedEvent:(NSString *)level andAfCustomerUserId:(NSString *)roleId;

/**
 * 选择职业
 */
+(void)gameChooseProfessionEvent:(NSString *)jobName;

/**
 * 境界等级
 */
+(void)gameRealmLevelEvent:(NSString *)realmLevel andAfCustomerUserId:(NSString *)roleId;

/**
 * 第一次付费
 */
+(void)firstPurchaseEvent;

/**
 * 付费记录事件
 */
+(void)inAppPurchaseEvent:(NSString *)priceStr andCurrency:(NSString *)currency;



/**
 * 暂停
 */
+(void)onPauseEvent;


/**
 * 继续
 */
+(void)onResumeEvent;


/**
 * 销毁
 */
+(void)onDestroyEvent;
@end
