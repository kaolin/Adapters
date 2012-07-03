// PostgreSQLAdapter.h
//
// Copyright (c) 2012 Mattt Thompson (http://mattt.me)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "SQLAdapter.h"

extern NSString * const PostgreSQLErrorDomain;

#pragma mark -

@interface PostgreSQLAdapter : NSObject <DBAdapter>
@end

#pragma mark -

@interface PostgreSQLConnection : NSObject <SQLConnection>
@end

#pragma mark -

@interface PostgreSQLDatabase : NSObject <SQLDatabase>
@end

#pragma mark -

@interface PostgreSQLTable : NSObject <SQLTable>
@end

#pragma mark -

@interface PostgreSQLField : NSObject <SQLField>

+ (PostgreSQLField *)fieldInResult:(void *)pgresult 
                           atIndex:(NSUInteger)fieldIndex;

- (id)objectForBytes:(const char *)bytes 
              length:(NSUInteger)length 
            encoding:(NSStringEncoding)encoding;

@end

#pragma mark -

@interface PostgreSQLTuple : NSObject <SQLTuple>

- (id)initWithValuesKeyedByFieldName:(NSDictionary *)keyedValues;

@end

#pragma mark -

@interface PostgreSQLResultSet : NSObject <SQLResultSet>

- (id)initWithResult:(void *)result;

@end
