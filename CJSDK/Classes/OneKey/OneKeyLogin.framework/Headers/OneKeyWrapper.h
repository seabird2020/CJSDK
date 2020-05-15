//
//  HelloWorld.h
//  OneKeyLogin
//
//  Created by ydz on 2020/3/2.
//  Copyright © 2020 chujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  @brief 预取号回调
 *  @param result 预取号结果
 */
typedef void(^PreLoginCallBack)(NSDictionary *result);
//左边已有帐号按钮被点击
typedef void(^LeftBottomBtnOnClick)(void);
//右边已有帐号按钮被点击
typedef void(^RightBottomBtnOnClick)(void);
//登录完成回调
typedef void(^LoginCompleteCallback)(NSDictionary *result);
@interface OneKeyWrapper : NSObject

+(instancetype)shareInst;
//左边已有帐号按钮被点击
@property(readwrite, strong, nonatomic) LeftBottomBtnOnClick mLeftBottomBtnOnClick;
//右边已有帐号按钮被点击
@property(readwrite, strong, nonatomic) RightBottomBtnOnClick mRightBottomBtnOnClick;
//游戏名称
@property(readwrite, strong, nonatomic) NSString *mGameName;

//初始化配置
-(void)initConfig:(NSString *) appKey gameName:(NSString *)gameName enableLogFlag:(BOOL)enableLog;
//是否初始化成功
-(BOOL)isInitSuccess;
//判断是否可以发起一键登录（预取号可以不用判断）
-(BOOL)checkVerifyEnable;
//预取号
-(void)preLogin:(PreLoginCallBack)callback;
/**
授权登录
@param vc 当前控制器
@param completion 登录结果
@parm  leftBtnOnClick 当点击左下已有帐号按钮的事件。
@parm  rightBtnOnClick 当点击右下帐号注册按钮的事件。
*/
-(void)startLogin:(UIViewController *) vc
       completion:(LoginCompleteCallback)completion whenLeftBottomBtnOnClick:(LeftBottomBtnOnClick)leftBtnOnClick
            whenRightBottomBtnOnClick:(RightBottomBtnOnClick)rightBtnOnClick;
//清除预取号缓存
-(void)clearPreLoginCache;
@end

NS_ASSUME_NONNULL_END
