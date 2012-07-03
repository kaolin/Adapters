// SQLAdapter.h
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
#import "DBAdapter.h"

@protocol SQLConnection;
@protocol SQLDatabase;
@protocol SQLTable;
@protocol SQLField;
@protocol SQLTuple;
@protocol SQLResultSet;

#pragma mark -

@protocol SQLConnection <DBConnection>

- (void)executeSQL:(NSString *)SQL
           success:(void (^)(id <SQLResultSet> resultSet, NSTimeInterval elapsedTime))success
           failure:(void (^)(NSError *error))failure;

- (id <SQLResultSet>)resultSetByExecutingSQL:(NSString *)SQL 
                                       error:(NSError *__autoreleasing *)error;

@property (readonly) NSArray *availableDatabases;

@end

#pragma mark -

@protocol SQLDatabase <DBDatabase>

@property (readonly) id <SQLConnection> connection;

@property (readonly) NSString *name;
@property (readonly) NSStringEncoding stringEncoding;

@property (readonly) NSArray *tables;

- (id)initWithConnection:(id <SQLConnection>)connection 
                    name:(NSString *)name
          stringEncoding:(NSStringEncoding)stringEncoding;

@end

#pragma mark -

@protocol SQLTable <DBDataSource, DBExplorableDataSource, DBQueryableDataSource, DBVisualizableDataSource>

@property (readonly, nonatomic) NSStringEncoding stringEncoding;

- (id)initWithDatabase:(id <SQLDatabase>)database
                  name:(NSString *)name
        stringEncoding:(NSStringEncoding)stringEncoding;

@end

#pragma mark -

@protocol SQLField <NSObject>

@property (readonly, nonatomic) NSUInteger index;
@property (readonly, nonatomic) NSString *name;
@property (readonly, nonatomic) DBValueType type;
@property (readonly, nonatomic) NSUInteger size;

@end

#pragma mark -

@protocol SQLTuple <DBRecord>

@property (readonly, nonatomic) NSUInteger index;

@end

#pragma mark -

@protocol SQLResultSet <DBResultSet>

@property (readonly, nonatomic) NSArray *fields;
@property (readonly, nonatomic) NSArray *tuples;

@end
