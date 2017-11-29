//
//  BLVirtualDeviceController.h
//  Let
//
//  Created by junjie.zhu on 16/8/30.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BLVirtualDeviceController : NSObject

+ (instancetype)sharedVDevController;

/**
 *  判断设备是否为虚拟设备
 *
 *  @param script
 *  @return
 */
- (BOOL)checkDeviceTypeIsVirtualByScript:(NSString *)script;

/**
 虚拟设备profile信息获取

 @param scriptPath
 @param 设备pid
 @return 
 */
- (NSString *)virtualDeviceProfileByPid:(NSString *)pid scriptPath:(NSString *)scriptPath;

/**
 *  虚拟设备控制
 *
 *  @param devinfo    设备信息
 *  @param subdevinfo 子设备信息
 *  @param dataStr    控制命令
 *  @param descStr    描述信息
 *  @return 
 */
- (NSString *)virtualDeviceControlWithDeviceInfo:(NSString *)devinfo subdevInfo:(NSString *)subdevinfo dataStr:(NSString *)dataStr descStr:(NSString *)descStr scriptPath:(NSString *)scriptPath;

@end
