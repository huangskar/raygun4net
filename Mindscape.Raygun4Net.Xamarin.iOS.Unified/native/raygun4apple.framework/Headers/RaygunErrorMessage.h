//
//  RaygunErrorMessage.h
//  raygun4apple
//
//  Created by Mitchell Duncan on 11/09/17.
//  Copyright © 2018 Raygun Limited. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef RaygunErrorMessage_h
#define RaygunErrorMessage_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RaygunErrorMessage : NSObject

@property (nonnull, nonatomic, copy) NSString *className;
@property (nonnull, nonatomic, copy) NSString *message;
@property (nullable, nonatomic, copy) NSString *signalName;
@property (nullable, nonatomic, copy) NSString *signalCode;
@property (nullable, nonatomic, strong) NSArray *stackTrace;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)init:(nonnull NSString *)className
         withMessage:(nonnull NSString *)message
      withSignalName:(nullable NSString *)signalName
      withSignalCode:(nullable NSString *)signalCode
      withStackTrace:(nullable NSArray *)stacktrace NS_DESIGNATED_INITIALIZER;

/*
 * Creates and returns a dictionary with the classes properties and their values.
 * Used when constructing the crash report that is sent to Raygun.
 *
 * @return a new Dictionary with the classes properties and their values.
 */
- (NSDictionary *)convertToDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* RaygunErrorMessage_h */
