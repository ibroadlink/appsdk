//
//  ControllerImpl.h
//  Let
//
//  Created by yzm on 16/5/19.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//
#import "BLConfigParam.h"
#import "BLDNADevice.h"

#import "BLBaseResult.h"
#import "BLBaseBodyResult.h"
#import "BLDeviceConfigResult.h"
#import "BLPairResult.h"
#import "BLBindDeviceResult.h"
#import "BLProfileStringResult.h"
#import "BLStdControlResult.h"
#import "BLPassthroughResult.h"
#import "BLUpdateDeviceResult.h"
#import "BLFirmwareVersionResult.h"
#import "BLDeviceTimeResult.h"
#import "BLQueryTaskResult.h"
#import "BLTaskDataResult.h"
#import "BLDownloadResult.h"
#import "BLSubDevListResult.h"
#import "BLSubDevAddResult.h"
#import "BLQueryResourceVersionResult.h"
#import "BLGetAPListResult.h"
#import "BLIRCodeInfoResult.h"
#import "BLIRCodeDataResult.h"
#import "BLAPConfigResult.h"
#import "BLSubdevBaseResult.h"

#import "BLQueryIRCodeParams.h"

typedef unsigned char *_Nullable(^BLReadPrivateDataBlock)(int, unsigned char *_Nullable);
typedef unsigned char *_Nullable(^BLWritePrivateDataBlock)(int, unsigned char *_Nullable, unsigned char *_Nullable);

/** 控制系统的协议,
 *  用于设备相关
 */
@protocol BLControllerImplDelegate <NSObject>

/**
 *  局域网中发现新设备时回调
 *  用户可以干预是否要添加此设备
 *
 *  @param device 设备信息
 *
 *  @return YES / NO, 允许添加返回YES, 反之NO
 */
- (Boolean)filterDevice:(BLDNADevice * _Nonnull)device;

/**
 *  局域网中发现新设备时回调
 *  用户是否自动添加设备到SDK(自动调用deviceAdd:接口)
 *
 *  @param device 设备信息
 *
 *  @return YES / NO, 允许添加返回YES, 反之NO
 */
- (Boolean)shouldAdd:(BLDNADevice *_Nonnull)device;

/**
 *  当新设备发现且用户允许添加 或者 设备信息更新时回调
 *
 *  @param device      设备信息
 *  @param isNewDevice 是否是未加入SDK管理的新设备
 */
- (void)onDeviceUpdate:(BLDNADevice *_Nonnull)device isNewDevice:(Boolean)isNewDevice;

/**
 *  设备状态改变回调
 *
 *  @param device 设备信息
 *  @param status 设备的当前状态
 */
- (void)statusChanged:(BLDNADevice *_Nonnull)device status:(BLDeviceStatusEnum)status;

@end

@interface BLControllerImpl : NSObject

/**
 *  代理
 */
@property (nonatomic, weak) id <BLControllerImplDelegate> _Nullable delegate;

- (instancetype _Nullable)initWithConfigParam:(BLConfigParam * _Nonnull)configParam;

/**
 *  获取SDK版本号
 *
 *  @return 版本号
 */
- (NSString *_Nonnull)getSDKVersion;

/**
 *  设置SDK仅局域网控制
 *
 *  @param localMode    是否仅局域网控制
 *
 *  @return 是否成功
 */
- (Boolean)setSDKOnlyLocalControl:(Boolean)localMode;

/**
 *  设置底层SDK的调试信息等级
 *
 *  @param logLevel      Log打印等级
 *
 *  @return 是否成功
 */
- (Boolean)setSDKRawDebugLevel:(BLDebugLevelEnum)logLevel;

/**
 *  设置底层SDK回调接口
 */
- (void)setSDKRawWithReadBlock:(BLReadPrivateDataBlock _Nullable )readBlock writeBlock:(BLWritePrivateDataBlock _Nullable )writeBlock;

/**
 *  开始扫描设备
 */
- (void)startProbe;

/**
 *  停止扫描设备
 */
- (void)stopProbe;

/**
 *  设备入网，采用全局配置参数中的超时时间
 *
 *  @param ssid     无线SSID
 *  @param password 对应的无线密码
 *
 *  @return 配置结果
 */
- (BLDeviceConfigResult *_Nonnull)deviceConfig:(NSString *_Nonnull)ssid
                                    password:(NSString *_Nonnull)password;

/**
 *  设备入网
 *
 *  @param ssid     无线SSID
 *  @param password 对应的无线密码
 *  @param version  配网版本 1,2,3
 *  @param timeout  超时时间
 *
 *  @return 配置结果
 */
- (BLDeviceConfigResult *_Nonnull)deviceConfig:(NSString *_Nonnull)ssid
                                      password:(NSString *_Nonnull)password
                                       version:(NSUInteger)version
                                     timeout:(NSUInteger)timeout;

/**
 *  取消设备入网
 *
 *  @return 取消结果
 */
- (BLBaseResult *_Nonnull)deviceConfigCancel;

/**
 *  设备配对
 *
 *  @param did 设备did
 *
 *  @return 配对结果
 */
- (BLPairResult *_Nonnull)pair:(NSString *_Nonnull)did;

/**
 设备配对

 @param device 设备信息
 @return 配对结果
 */
- (BLPairResult *_Nonnull)pairWithDevice:(BLDNADevice *_Nonnull)device;

/**
 *  查询设备的网络状态
 *
 *  @param did 设备的did
 *
 *  @return 当前设备网络状态
 */
- (BLDeviceStatusEnum)queryDeviceState:(NSString *_Nonnull)did;

/**
 *  查询设备的远程状态
 *
 *  @param did 设备的did
 *
 *  @return 当前设备网络状态
 */
- (BLDeviceStatusEnum)queryDeviceRemoteState:(NSString *_Nonnull)did;

/**
 *  查询设备的局域网IP地址
 *
 *  @param did 设备的did
 *
 *  @return 局域网IP地址，若非局域网，则返回 @""
 */
- (NSString *_Nonnull)queryDeviceIp:(NSString *_Nonnull)did;

/**
 *  添加设备列表到SDK
 *
 *  @param deviceArray 设备列表 <DNADevice>
 */
- (void)addDeviceArray:(NSArray<BLDNADevice *> *_Nonnull)deviceArray;

/**
 *  添加单个设备到SDK
 *
 *  @param device 设备信息
 */
- (void)addDevice:(BLDNADevice *_Nonnull)device;

/**
 *  从SDK中批量删除设备列表
 *
 *  @param deviceArray 设备列表 <DNADevice>
 */
- (void)removeDeviceArray:(NSArray<BLDNADevice *> *_Nonnull)deviceArray;

/**
 *  从SDK中删除指定的设备信息
 *
 *  @param device 设备信息
 */
- (void)removeDevice:(BLDNADevice *_Nonnull)device;

/**
 *  从SDK中删除所有的设备信息
 */
- (void)removeAllDevice;

/**
 *  绑定单个设备到用户
 *
 *  @param device 设备信息
 *
 *  @return 绑定结果
 */
- (BLBindDeviceResult *_Nonnull)bindDeviceWithServer:(BLDNADevice *_Nonnull)device;

/**
 *  批量查询设备的绑定状态
 *
 *  @param deviceArray 设备列表
 *
 *  @return 查询结果
 */
- (BLBindDeviceResult *_Nonnull)queryDeviceArrayBinded:(NSArray<BLDNADevice *> *_Nonnull)deviceArray;

/**
 清除指定设备Profile缓存

 @param pid 设备pid
 */
- (void)cleanProfileCahe:(NSString *_Nonnull)pid;
/**
 *  获取设备的产品profile信息
 *
 *  @param did         设备的did
 *  @param profilePath 设备的脚本存放路径
 *
 *  @return 结果信息
 */
- (BLProfileStringResult *_Nonnull)queryProfile:(NSString *_Nonnull)did
                                  profilePath:(NSString *_Nullable)profilePath;

/**
 *  获取设备的产品profile信息
 *
 *  @param pid         设备的pid
 *  @param profilePath 设备的脚本存放路径
 *
 *  @return 结果信息
 */
- (BLProfileStringResult *_Nonnull)queryProfileByPid:(NSString *_Nonnull)pid
                                         profilePath:(NSString *_Nullable)profilePath;

/**
 Control sub device with specify the script.
 
 @param did             Control wifi device did
 @param sDid            Control sub device did. If sdid = nil, just control wifi device.
 @param stdData         Control data
 @param action          Control action - "get" / "set"
 @param scriptPath      Control device script. If scriptPath = nil, find device script in default store path.
 @param sendcount       Control device send count. Default by BLConfigParam.controllerSendCount
 @return                Control result
 */
- (BLStdControlResult *_Nonnull)dnaControl:(NSString *_Nonnull)did
                                 subDevDid:(NSString *_Nullable)sDid
                                   stdData:(BLStdData *_Nonnull)stdData
                                    action:(NSString *_Nonnull)action
                                scriptPath:(NSString *_Nullable)scriptPath
                                 sendcount:(NSUInteger)sendcount;

/**
 *  设备标准控制
 *
 *  @param did             设备的did
 *  @param sDid            子设备did
 *  @param dataStr         控制指令内容
 *  @param command         控制命令
 *  @param scriptPath      控制脚本绝对路径
 *  @param sendcount       控制命令发送次数
 *
 *  @return 控制结果
 */
- (NSString *_Nonnull)dnaControl:(NSString *_Nonnull)did
                       subDevDid:(NSString *_Nullable)sDid
                         dataStr:(NSString *_Nonnull)dataStr
                         command:(NSString *_Nonnull)command
                      scriptPath:(NSString *_Nullable)scriptPath
                       sendcount:(NSUInteger)sendcount;

/**
 *  设备透传控制
 *
 *  @param did             设备的did
 *  @param sDid            子设备did
 *  @param passthroughData 透传数据内容
 *
 *  @return 控制结果
 */
- (BLPassthroughResult *_Nonnull)dnaPassthrough:(NSString *_Nonnull)did
                                      subDevDid:(NSString *_Nullable)sDid
                                passthroughData:(NSData *_Nonnull)passthroughData;


/**
 获取发送的二进制数据

 @param did                 设备的did
 @param sDid                子设备did
 @param stdData             标准控制指令
 @param action              动作 "set" or "get"， 若为其他值，则默认为"get"
 @return 发送数据
 */
- (NSData *_Nonnull)dnaControlData:(NSString *_Nonnull)did
                         subDevDid:(NSString *_Nullable)sDid
                           stdData:(BLStdData *_Nonnull)stdData
                            action:(NSString *_Nonnull)action;

/**
 *  修改设备信息
 *
 *  @param did    设备的did
 *  @param name   设备的名称
 *  @param locked 设备的锁定状态
 *
 *  @return 修改结果
 */
- (BLUpdateDeviceResult *_Nonnull)updateDeviceInfo:(NSString *_Nonnull)did
                                            name:(NSString *_Nonnull)name
                                            lock:(Boolean)locked;

/**
 *  获取设备的固件版本号
 *
 *  @param did 设备的did
 *
 *  @return 版本结果以及信息
 */
- (BLFirmwareVersionResult *_Nonnull)queryFirmwareVersion:(NSString *_Nonnull)did;


/**
 Query sub device firmware version

 @param did wifi device did
 @param sdid sub device did
 @return Query result
 */
- (BLFirmwareVersionResult *_Nonnull)querySubDeviceFirmwareVersion:(NSString *_Nonnull)did sdid:(NSString *_Nonnull)sdid;

/**
 *  设备固件升级
 *
 *  @param did 设备的did
 *  @param url 固件的下载链接地址
 *
 *  @return 升级结果
 */
- (BLBaseResult *_Nonnull)upgradeFirmware:(NSString *_Nonnull)did
                                    url:(NSString *_Nonnull)url;

/**
 *  查询设备所在服务器时间
 *
 *  @param did 设备的did
 *
 *  @return 服务器时间
 */
- (BLDeviceTimeResult *_Nonnull)queryDeviceTime:(NSString *_Nonnull)did;

/**
 *  查询设备的任务列表<含周期任务与定时任务>
 *
 *  @param did 设备的did
 *  @param sdid 子设备的did 
 *  @param scriptPath 脚本路径
 *  @return 查询结果以及任务信息
 */
- (BLQueryTaskResult *_Nonnull)queryTask:(NSString *_Nonnull)did sDid:(NSString *_Nullable)sdid scriptPath:(NSString *_Nullable)scriptPath;

/**
 *  新增或修改定时任务
 *
 *  @param did       设备的did
 *  @param timerInfo 定时任务基础信息
 *  @param stdData   任务内容，同标准控制设置
 *  @param isAdd     YES: 增加  NO: 修改
 *  @param sdid 子设备的did
 *  @param scriptPath 脚本路径
 *  @return 添加结果以及所有任务基础信息
 */
- (BLQueryTaskResult *_Nonnull)addOrUpdateTimerTask:(NSString *_Nonnull)did
                                               sDid:(NSString *_Nullable)sdid
                                        timerInfo:(BLTimerInfo *_Nonnull)timerInfo
                                          stdData:(BLStdData *_Nonnull)stdData
                                         scriptPath:(NSString *_Nullable)scriptPath
                                            isAdd:(Boolean)isAdd;

/**
 *  新增或修改周期任务
 *
 *  @param did       设备的did
 *  @param timerInfo 周期任务基础信息
 *  @param stdData   任务内容，同标准控制设置
 *  @param isAdd     YES: 增加  NO: 修改
 *  @param sdid 子设备的did
 *  @param scriptPath 脚本路径
 *
 *  @return 添加结果以及所有任务基础信息
 */
- (BLQueryTaskResult *_Nonnull)addOrUpdatePeriodTask:(NSString *_Nonnull)did
                                                sDid:(NSString *_Nullable)sdid
                                        periodInfo:(BLPeriodInfo *_Nonnull)periodInfo
                                           stdData:(BLStdData *_Nonnull)stdData
                                          scriptPath:(NSString *_Nullable)scriptPath
                                             isAdd:(Boolean)isAdd;

/**
 *  删除定时或周期任务
 *
 *  @param did         设备的did
 *  @param isTimer     YES: 定时任务  NO:周期任务
 *  @param taskIndex   任务位标
 *  @param sdid 子设备的did
 *  @param scriptPath 脚本路径
 *
 *  @return 修改结果以及所有任务基础信息
 */
- (BLQueryTaskResult *_Nonnull)delTask:(NSString *_Nonnull)did
                                  sDid:(NSString *_Nullable)sdid
                             isTimer:(Boolean)isTimer
                           taskIndex:(NSUInteger)taskIndex
                            scriptPath:(NSString *_Nullable)scriptPath;

/**
 *  查询定时或周期任务内容
 *
 *  @param did         设备的did
 *  @param isTimer     YES: 定时任务  NO:周期任务
 *  @param taskIndex   任务位标
 *  @param sdid 子设备的did
 *  @param scriptPath 脚本路径
 *
 *  @return 查询结果以及任务内容
 */
- (BLTaskDataResult *_Nonnull)taskData:(NSString *_Nonnull)did
                                  sDid:(NSString *_Nullable)sdid
                             isTimer:(Boolean)isTimer
                           taskIndex:(NSUInteger)taskIndex
                            scriptPath:(NSString *_Nullable)scriptPath;

/**
 *  获取设备产品UI包的版本号
 *
 *  @param pidList 设备的pid数组
 *
 *  @return 获取结果以及UI包版本信息
 */
- (BLQueryResourceVersionResult *_Nonnull)queryUIVersion:(NSArray *_Nonnull)pidList;

/**
 *  获取设备控制脚本的版本号
 *
 *  @param pidList 设备的pid数组
 *
 *  @return 操作结果以及控制脚本版本号信息
 */
- (BLQueryResourceVersionResult *_Nonnull)queryScriptVersion:(NSArray *_Nonnull)pidList;

/**
 查询资源文件版本信息

 @param type “ui” “script”
 @param pidList 设备pid列表
 @return
 */
- (BLQueryResourceVersionResult *_Nonnull)queryResourceVersionWithType:(NSString *_Nonnull)type pidList:(NSArray *_Nonnull)pidList;


/**
 *  获取指定产品PID的设备控制UI包的绝对路径
 *
 *  @param pid 设备的产品PID
 *
 *  @return UI包路径
 */
- (NSString *_Nonnull)queryUIPath:(NSString *_Nonnull)pid;

/**
 获取红外码脚本存储路径

 @return 红外码脚本存储路径
 */
- (NSString *_Nonnull)queryIRCodeScriptPath;

/**
 *  获取设备控制脚本的存储路径
 *
 *  @return 脚本路径存储路径
 */
- (NSString *_Nonnull)queryScriptPath;

/**
 获取设备控制脚本名称（全路径）

 @param pid 设备产品PID
 @return 脚本文件名（全路径）
 */
- (NSString *_Nonnull)queryScriptFileName:(NSString *_Nonnull)pid;

/**
 *  下载设备的控制UI包
 *
 *  @param pid               设备的PID
 *  @param uiid              UIID，通过queryUIVersion返回
 *  @param completionHandler 操作结束返回
 */
- (void)downloadUI:(nonnull NSString *)pid completionHandler:(nullable void (^)(BLDownloadResult * _Nonnull result))completionHandler;

/**
 *  下载设备的控制脚本
 *
 *  @param pid              设备的产品PID
 *  @param completionHandler 操作结束返回
 */
- (void)downloadScript:(nonnull NSString *)pid completionHandler:(nullable void (^)(BLDownloadResult * _Nonnull result))completionHandler;

/**
 设备授权
 
 @param did 设备DID
 @param accesskey 第三方云获取的云端通信凭证
 @param tpid 第三方平台接入时该产品类型，可为空
 @param attr 设备属性
 @param completionHandler 操作结果block
 */
- (void)dnaProxyAuth:(NSString *_Nonnull)did accesskey:(NSString *_Nonnull)accesskey tpid:(NSString *_Nonnull)tpid attr:(NSString *_Nonnull)attr completionHandler:(nullable void (^)(BLBaseResult * _Nonnull result))completionHandler;

/**
 取消设备授权
 
 @param did 设备DID
 @param accesskey 第三方云获取的云端通信凭证
 @return
 */
- (void)dnaProxyDisauth:(NSString *_Nonnull)did accesskey:(NSString *_Nonnull)accesskey completionHandler:(nullable void (^)(BLBaseResult * _Nonnull result))completionHandler;

/**
 通知网关设备进入扫描子设备的模式
 
 @param did 主设备Did
 @param subPid 子设备Pid
 @return 操作结果
 */
- (BLSubdevBaseResult *_Nonnull)subDevScanStartWithDid:(NSString *_Nonnull)did subPid:(NSString *_Nullable)subPid;

/**
 通知网关设备退出扫描子设备的模式
 
 @param did 主设备Did
 @return 操作结果
 */
- (BLSubdevBaseResult *_Nonnull)subDevScanStopWithDid:(NSString *_Nonnull)did;

/**
 获取扫描到的新子设备的列表
 
 @param did 主设备Did
 @param index 页码
 @param count 每页个数
 @return  操作结果
 */
- (BLSubDevListResult *_Nonnull)subDevNewListQueryWithDid:(NSString *_Nonnull)did index:(NSInteger)index count:(NSInteger)count subPid:(NSString *_Nullable)subPid;

/**
 添加新子设备到网关设备
 
 @param did 主设备Did
 @param subDevInfo 子设备信息
 @return 操作结果
 */
- (BLSubdevBaseResult *_Nonnull)subDevAddWithDid:(NSString *_Nonnull)did subDevInfo:(BLDNADevice *_Nonnull)subDevInfo;

/**
 查询子设备添加进度
 
 @param did 主设备Did
 @param sDid 子设备Did
 @return 操作结果
 */
- (BLSubDevAddResult *_Nonnull)subDevAddResultQueryWithDid:(NSString *_Nonnull)did subDevDid:(NSString *_Nonnull)sDid;

/**
 从网关设备中删除指定的子设备
 
 @param did 主设备Did
 @param sDid 子设备Did
 @return 操作结果
 */
- (BLSubdevBaseResult *_Nonnull)subDevDelWithDid:(NSString *_Nonnull)did subDevDid:(NSString *_Nonnull)sDid;

/**
 修改网关设备中指定的子设备信息
 
 @param did 主设备DID
 @param sDid 子设备Did
 @param name 名称
 @return 操作结果
 */
- (BLSubdevBaseResult *_Nonnull)subDevModifyDid:(NSString *_Nonnull)did subDevDid:(NSString *_Nonnull)sDid name:(NSString *_Nonnull)name;

/**
 获取已经添加的子设备列表
 
 @param did 主设备DID
 @param index 页码
 @param count 每页个数
 @return 操作结果
 */
- (BLSubDevListResult *_Nonnull)subDevListQueryWithDid:(NSString *_Nonnull)did index:(NSInteger)index count:(NSInteger)count;

/**
 AP 配置

 @param ssid
 @param password
 @param type
 @param timeout 
 @return
 */
- (BLAPConfigResult *_Nonnull)deviceAPConfig:(NSString *_Nonnull)ssid password:(NSString *_Nonnull)password type:(NSInteger)type timeout:(NSUInteger)timeout;

/**
 获取AP List

 @param timeout
 @return
 */
- (BLGetAPListResult *_Nonnull)deviceAPList:(NSInteger)timeout;

/**
 查询dnacontrol发送命令记录

 @param did 设备did
 @return data list
 */
- (NSArray *_Nonnull)queryDnacontrolDataWithDid:(NSString *_Nonnull)did;


/**
 查询设备数据上报
 */
- (BLBaseBodyResult *_Nonnull)queryDeviceDataWithDid:(NSString *_Nonnull)did familyId:(NSString *_Nullable)familyId startTime:(NSString *_Nonnull)startTime endTime:(NSString *_Nonnull)endTime;

@end
