//
//  HWLocationManager.h
//  HyWin
//
//  Created by wwp on 2017/4/21.
//  Copyright © 2017年 wwp. All rights reserved.
//


#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, SBaseHandlerReturnType) {
    SBaseHandlerReturnTypeVerify,      //数据验证
    SBaseHandlerReturnTypeSuccess,      //数据操作成功
    SBaseHandlerReturnTypeAbnormal,     //数据操作异常
    SBaseHandlerReturnTypeFailed,       //网络获取失败(无网络)
    SBaseHandlerReturnTypeTimeout,      //网络获取失败(网络超时)
    SBaseHandlerReturnTypeNoData,       //获取数据为空
    SBaseHandlerReturnTypeNoMoreData,   //没有获取到更多数据
};

typedef void (^baseHandlerReturnType)(SBaseHandlerReturnType type);

typedef void (^GainLocationCompleteBlock) (id sender,NSString *locationProvince,NSString *locationCity,NSString *locationArea,SBaseHandlerReturnType returnType);
@interface HWLocationManager : NSObject
@property (nonatomic,copy) GainLocationCompleteBlock gainLocationCompletBlock;
@property (nonatomic,strong) NSString *longitude;//经度
@property (nonatomic,strong) NSString *latitude;//纬度
@property (nonatomic,strong) NSString *locationProvince;//省
@property (nonatomic,strong) NSString *locationCity;//城市
@property (nonatomic,strong) NSString *locationSubLocality;//区域
@property (nonatomic,strong) NSString *locationAddress;//具体街道
+(instancetype) shareInstance;
-(void)getStartLocation;

-(void)gainLocationCompleteBlock:(GainLocationCompleteBlock) block;
@end
extern HWLocationManager *hwLocationManger;
