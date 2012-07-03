// MongoDBAdapter.h
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

@class MongoDBAdapter;
@class MongoDBConnection;
@class MongoDBDatabase;
@class MongoDBCollection;
@class MongoDBResultSet;
@class MongoDBDocument;

@interface MongoDBAdapter : NSObject <DBAdapter>
@end

@interface MongoDBConnection : NSObject <DBConnection>

- (id <DBResultSet>)resultSetByRunningCommand:(id)command 
                                   onDatabase:(MongoDBDatabase *)database
                                        error:(NSError **)error;

- (void)runCommand:(id)command 
        onDatabase:(id <DBDatabase>)database
           success:(void (^)(MongoDBResultSet *resultSet, NSTimeInterval elapsedTime))success
           failure:(void (^)(NSError *error))failure;

@end

@interface MongoDBDatabase : NSObject <DBDatabase>

- (id)initWithConnection:(MongoDBConnection *)connection
              attributes:(NSDictionary *)attributes;

@end

@interface MongoDBCollection : NSObject <DBDataSource, DBExplorableDataSource, DBQueryableDataSource>

@property (nonatomic, readonly) NSString *namespace;

- (id)initWithDatabase:(MongoDBDatabase *)database
            attributes:(NSDictionary *)attributes;

@end

@interface MongoDBResultSet : NSObject <DBResultSet>

- (id)initWithCursor:(void *)cursor;

@end

@interface MongoDBDocument :  NSObject <DBRecord>

@property (nonatomic, strong, readonly) NSString *key;
@property (nonatomic, strong, readonly) id value;

- (id)initWithDictionary:(NSDictionary *)attributes;

@end