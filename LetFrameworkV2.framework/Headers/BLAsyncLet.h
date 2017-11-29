//
//  BLAsyncLet.h
//  Let
//
//  Created by zjjllj on 2017/9/12.
//  Copyright © 2017年 BroadLink Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLConstants.h"

@interface BLAsyncLet : NSObject

/**
 Init SDK with params
 
 @param params
 @return Init result
 */
+ (NSString *)sdkInit:(NSString *)params;

/**
 Destory SDK
 */
+ (void)sdkDestroy;

/**
 Manage account
 
 @param action
 @param params
 @return Manage result
 */
+ (void)accountManagement:(NSString *)action params:(NSString *)params callback:(BLLetAsyncRequestCallback)callback;

/**
 Manage family
 
 @param action
 @param params
 @return Manage result
 */
+ (void)familyManagement:(NSString *)action params:(NSString *)params callback:(BLLetAsyncRequestCallback)callback;

/**
 Config Device
 
 @param action
 @param params
 @param callback
 */
+ (void)deviceConfig:(NSString *)action params:(NSString *)params callback:(DeviceConfigCallback)callback;

/**
 Device Control
 
 @param action
 @param endPointInfo
 @param subEndPointInfo
 @param params
 @return
 */
+ (void)deviceControl:(NSString *)action endPointInfo:(NSString *)endPointInfo subEndPointInfo:(NSString *)subEndPointInfo params:(NSString *)params callback:(BLLetAsyncRequestCallback)callback;

/**
 subDevice Management
 
 @param action
 @param params
 @param callback
 */
+ (void)subDeviceManagement:(NSString *)action endPointInfo:(NSString *)endPointInfo params:(NSString *)params callback:(SubDeviceManagementCallback)callback;
/**
 Manage product
 
 @param action
 @param params
 @return Manage result
 */
+ (void)productManagement:(NSString *)action params:(NSString *)params callback:(BLLetAsyncRequestCallback)callback;

/**
 IRcode Service
 
 @param action
 @param params
 @return
 */
+ (void)iRService:(NSString *)action params:(NSString *)params callback:(BLLetAsyncRequestCallback)callback;

@end
