//
//  BLProxyHttpAccessor.h
//  Let
//
//  Created by zjjllj on 2016/9/26.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//

#import "BLBaseHttpAccessor.h"

@interface BLProxyHttpAccessor : BLBaseHttpAccessor

/**
 *  Proxy系统异步POST请求
 *
 *  @param url               HTTP链接地址
 *  @param head              HTTP header
 *  @param dataStr           请求数据
 *  @param timeout           超时时间
 *  @param completionHandler 请求结果
 */
- (void)generalPost:(nonnull NSString *)url head:(nullable NSDictionary *)head data:(nonnull NSData *)data timeout:(NSUInteger)timeout completionHandler:(nullable void (^)(NSData * __nullable data, NSError * __nullable error))completionHandler;

@end
