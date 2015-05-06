//
//  NSObject+Swizzling.h
//  GDSMP3
//
//  Created by gauravds on 5/6/15.
//  Copyright (c) 2015 punchh. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@interface NSObject (Swizzling)
+ (void)superClass:(Class)class
     orignalMethod:(SEL)originalSelector
         newMethod:(SEL)swizzledSelector;
@end
@implementation NSObject (Swizzling)
+ (void)superClass:(Class)class
     orignalMethod:(SEL)originalSelector
         newMethod:(SEL)swizzledSelector {
    Method originalMethod = class_getInstanceMethod(class, originalSelector);
    Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);
    
    // When swizzling a class method, use the following:
    // Class class = object_getClass((id)self);
    // ...
    // Method originalMethod = class_getClassMethod(class, originalSelector);
    // Method swizzledMethod = class_getClassMethod(class, swizzledSelector);
    
    BOOL didAddMethod =
    class_addMethod(class,
                    originalSelector,
                    method_getImplementation(swizzledMethod),
                    method_getTypeEncoding(swizzledMethod));
    
    if (didAddMethod) {
        class_replaceMethod(class,
                            swizzledSelector,
                            method_getImplementation(originalMethod),
                            method_getTypeEncoding(originalMethod));
    } else {
        method_exchangeImplementations(originalMethod, swizzledMethod);
    }
}
@end