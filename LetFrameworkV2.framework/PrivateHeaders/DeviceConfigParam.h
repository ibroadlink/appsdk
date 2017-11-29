//
//  DeviceConfigParam.h
//  Let
//
//  Created by yzm on 16/5/16.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceConfigParam : NSObject

/**
 *  无线SSID
 */
@property (nonatomic, strong, getter=getSsid) NSString *ssid;

/**
 *  无线密码
 */
@property (nonatomic, strong, getter=getPassword) NSString *password;

/**
 *  无线网关地址
 */
@property (nonatomic, strong, getter=getGatewayaddr) NSString *gatewayaddr;

@end
