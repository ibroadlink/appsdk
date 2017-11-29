//
//  ProbeDevice.h
//  Let
//
//  Created by yzm on 16/5/19.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLDNADevice.h"

@interface BLProbeDevice : BLDNADevice

/** 远程状态刷新flag */
@property (nonatomic, assign, getter=getRefreshStateFlag) Boolean refreshStateFlag;

/**
 *  通过DNADevice进行初始化
 *
 *  @param device 设备信息
 *
 *  @return 实例化
 */
- (instancetype)initWithDNADevice:(BLDNADevice *)device;

/**
 *  从中获取DNADevice的实例
 *
 *  @return DNADevice
 */
- (BLDNADevice *)copyDNADevice;

/**
 *  将设备信息转换为json字符串
 *
 *  @return json
 */
- (NSString *)toJsonString;

@end
