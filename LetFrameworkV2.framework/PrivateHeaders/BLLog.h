//
//  BLLog.h
//  Let
//
//  Created by uuu on 16/6/12.
//  Copyright © 2016年 BroadLink Co., Ltd. All rights reserved.
//

#ifndef BLLog_h
#define BLLog_h

extern int BL_NSLOG_LEVEL;

#define BLLogError(frmt, ...)    do{ if(BL_NSLOG_LEVEL >= 1) NSLog((@"[BLLet ERROR]"frmt), ##__VA_ARGS__); } while(0)
#define BLLogWarn(frmt, ...)     do{ if(BL_NSLOG_LEVEL >= 2) NSLog((@"[BLLet WARN]"frmt), ##__VA_ARGS__); } while(0)
#define BLLogDebug(frmt, ...)    do{ if(BL_NSLOG_LEVEL >= 3) NSLog((@"[BLLet DEBUG]"frmt), ##__VA_ARGS__); } while(0)
#define BLLogVerbose(frmt, ...)  do{ if(BL_NSLOG_LEVEL >= 4) NSLog((@"[BLLet VERBOSE]"frmt), ##__VA_ARGS__); } while(0)

#endif /* BLLog_h */
