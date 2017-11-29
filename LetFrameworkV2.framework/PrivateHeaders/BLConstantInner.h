//
//  BLConstantInner.h
//  Let
//
//  Created by zhujunjie on 2017/7/11.
//  Copyright © 2017年 BroadLink Co., Ltd. All rights reserved.
//

#ifndef BLConstantInner_h
#define BLConstantInner_h
/** 错误日志上报的EventID **/
static NSString * const kPickErrorEventId = @"10001";
/** 崩溃日志上报的EventID **/
static NSString * const kPickCrashEventId = @"10002";
/** APP信息上报的EventID **/
static NSString * const kPickDataEventId = @"10003";
/** 错误日志上报的EventLabel **/
static NSString * const kPickErrorEventLabel = @"app error";
/** 崩溃日志上报的EventLabel **/
static NSString * const kPickCrashEventLabel = @"app crash";
/** APP信息上报的EventLabel **/
static NSString * const kPickDataEventLabel = @"app data";

#pragma mark - 错误信息返回
static NSString * const kSuccessMsg = @"Success";
static NSString * const kErrorMsgUnknownError = @"Unknown error";
static NSString * const kErrorMsgNotLogin = @"Not login";
static NSString * const kErrorMsgInputParam = @"Params input error";
static NSString * const kErrorMsgServerReturn = @"Server has not return data";
static NSString * const kErrorMsgInputLicense = @"Please input license";
static NSString * const kErrorMsgInitSdkFirst = @"Please init sdk first";
static NSString * const kErrorMsgNotSupportAction = @"Not support this action";
static NSString * const kErrorMsgConfigErrorDevice = @"EasyConfig error device";
static NSString * const kErrorMsgConfigTimeout = @"EasyConfig timout";
static NSString * const kErrorMsgCannotFindDevice = @"Cannot find specified device";
static NSString * const kErrorMsgRequestFast = @"HTTP request too fast";
static NSString * const kErrorMsgRequestDns = @"DNS resolution failed";
static NSString * const kErrorMsgRequestResource = @"Query resources error";
static NSString * const kErrorMsgDeviceNotSupport = @"Device is not supported by this license";

#endif /* BLConstantInner_h */
