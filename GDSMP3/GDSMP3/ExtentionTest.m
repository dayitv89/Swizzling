//
//  ExtentionTest.m
//  GDSMP3
//
//  Created by gauravds on 5/6/15.
//  Copyright (c) 2015 punchh. All rights reserved.
//

#import "ExtentionTest.h"
#import "NSObject+Swizzling.h"


@implementation ViewController(SwizzlingTest)
+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [self superClass:[self class]
           orignalMethod:@selector(viewDidLoad)
               newMethod:@selector(gds_viewDidLoad)];
        
        [self superClass:[self class]
           orignalMethod:@selector(viewWillAppear:)
               newMethod:@selector(gds_viewWillAppear:)];
    });
}



- (void)gds_viewDidLoad {
    NSLog(@"Child Class viewDidLoad");
    [self gds_viewDidLoad]; // super calling
}

- (void)gds_viewWillAppear:(BOOL)animated {
    [self gds_viewWillAppear:animated]; // super calling
    NSLog(@"Child class viewWillAppear:");
}

@end
