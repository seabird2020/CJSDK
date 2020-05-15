//
//  CJSDKDataGA.h
//  CJSDKDataGA
//
//  Created by Apple on 15-1-19.
//  Copyright (c) 2015年 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import "CJOautn.h"
//#import "CJIAPManager.h"
// 性别
typedef enum {
    CJ_kGenderUnknown = 0,     // 未知
    CJ_kGenderMale = 1,        // 男
    CJ_kGenderFemale = 2       // 女
} CJGAGender;

// 登录失败类型
typedef enum
{
    CJ_kLoginFailedByNeworkResponse,//因网络反馈,登录失败
    CJ_kLoginFailedByCloseButton,   //因关闭登录面板,登录失败
}CJLoginFailedType;




/**
 *  @brief 支付开关回调
 *
 *  @param paySwitch 支付开关，@"0":苹果支付， @"1":初见支付， nil:请求失败
 */
typedef void(^CJBeforeAuthentationCallBack)(int volide);

typedef void(^CJOautnCallBack)(NSString *oauth);

typedef void(^CJIAPManagerCallBack)(long iapMan);

typedef void(^CJShopVariantsCallBack)(NSDictionary *shopDict);

typedef void(^CJWXShareCallBack)(int wxVolide);
/**
 *  登录代理回调
 */
@protocol CJLoginDelegate <NSObject>

@required

/**
 *  登录成功
 *
 *  @param userLoginAccessToken      个人用户登录后accessToken值
 *  @param userName     用户名
 *
 */
-(void)loginSuccess:(NSString *)userLoginAccessToken userId:(NSString *)userId;

/**
 *  个人中心切换账号
 */
-(void)userSwitchAccount;

/**
 *  登录失败
 *
 *  @param type      失败类型
 *  @param errorInfo 错误信息
 */
-(void)loginFail:(CJLoginFailedType)type errorInfo:(NSString *)errorInfo;

/**
 *  获取用户年龄段及用户类型
 *
 */
-(void)loginUserRealNameInfoWithUserType:(NSString *)userType userChannel:(NSString *)userChannel;

@optional

@end
/**
 *  支付代理回调
 */
@protocol CJIAPDelegate <NSObject>

@required


/**
 *  支付成功
 */
-(void)paySuccessCallBack;

/**
 *  支付失败
 */
-(void)payFailCallBack:(NSString *)errorStr;
@optional

@end
///////////////////////////////////////////////////////////////////////////////////////
///SDK主类
@interface CJSDKDataGA: NSObject


/**
 *  开关日志(日志默认开启)
 *
 *  @param enableNSLog   是否开启使用NSLog输入日志到output面板中,YES表示开启,NO表示不开启
 *  @param enableFileLog 是否开启使用写日志文件,YES表示开启,NO表示不开启
 */
//+(void)enableLog:(BOOL)enableNSLog enableFileLog:(BOOL)enableFileLog;



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

+(void)deviceOrientationMask:(BOOL)isForcePortrait andIsForceLandscape:(BOOL)isForceLandscape;

/**
 *  激活
 */
+(void)initActivatedEvent;

/**
 *  启动闪屏
 */
+(void)splashStartRequestedEvent:(NSString *)label andStatus:(NSString *)status;

/**
 *  获取游客访问资源服务器
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
 * 获取客户端token
 */
+(void)upsOauthTokenCallBack:(void(^)(NSString *clientTOken))callBack;


/**
 * 获取配置项
 */
+(void)upsSettingsCallBack:(void(^)(NSString *jgKay,NSString *jgMasterSecret))callBack;



/**
 *  登录
 *  @param delegate         登录代理,处理登录成功与失败
 *  @param isShowSuccessDlg YES表示需要显示登录成功对话框,NO表示不需要
 */
+(void)onLogin:(id<CJLoginDelegate>)delegate isShowSuccessDlg:(BOOL)isShowSuccessDlg;


/**
 * 区服加载请求结果
 */

+(void)gameServerListedEvent:(NSString *)label andStatus:(NSString *)status;


/**
 * 区服登录请求结果
 */
+(void)gameServerLoggedinEvent:(NSString *)label andStatus:(NSString *)status;


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
 * 切换进入后台
 */
+(void)gameBackgroundSwitchedEvent:(NSString *)label;


/**
 * 切换进入前台
 */
+(void)gameForegroundSwitchedEvent:(NSString *)label;

/**
 *发起充值申请前传入用户等级
 **/
+(void)payRequestLevel:(NSString *)level;


/**
 * 发起充值申请前进行用户实名状态处理
 */
+(void)getBeforeAuthWithCallback:(CJBeforeAuthentationCallBack)callback;



/**
 * 等级变化
 */
+(void)gameLevelChangedEvent:(NSString *)level andAfCustomerUserId:(NSString *)rold;

/**
 * 任务变化
 */
+(void)gameTaskMovedEvent:(NSString *)gameTaskStr andAfCustomerUserId:(NSString *)rold;





/**
 * 加入公会
 */
+(void)gameUnionUserJoinedEventAndAfCustomerUserId:(NSString *)rold;


/**
 * 自定义事件
 */
+(void)customizedEvent:(NSString *)label andCategory:(NSString *)category andCustomArray:(NSArray *)customArray;

/**
 * 切换账号
 */
+(void)onUpsSwitchAccount:(id<CJLoginDelegate>)delegate;


+(void)mainSwitchAccount;


/**
 * 个人中心点击切换账号退出个人中心页面（退出当前SDK界面）
 */

+(void)onSwitchAccountDissView;


+(void)loadOauthWithClientID:(NSString *)clientID andClientSecret:(NSString *)clientSecret Oauth:(CJOautnCallBack)oauthyCallBack;

/**
 *  支付-店铺中心

 */
+(void)loadPayShopVariants:(id<CJIAPDelegate>)payDelegate callBack:(CJShopVariantsCallBack)shopCallBack;



/*
 发起充值申请

*/
+(void)loadPayCheckoutDeveloperPayload:(NSString *)developerPayload andServerId:(NSString *)serverId andServerName:(NSString *)serverName andRegionId:(NSString *)regionId andRegionName:(NSString *)regionName andRoleId:(NSString *)roleId andRoleName:(NSString *)roleName andVariantId:(NSString *)variantId;


/**
 * 个人中心
 */
+(void)loadUserCenterWithCjAccessToken;
/**
 *  取得设备ID
 *
 *  @return 设备ID字符串
 */
+(NSString *)getDeviceId;

/**
 *  暂停
 */
+(void)onPause;

/**
 *  继续
 */
+(void)onResume;
/**
 *  销毁
 */
+(void)onDestroy;

/**
 *  补单机制
 */
+(void)cjPayStart;

@end






