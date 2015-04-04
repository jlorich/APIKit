//
//  APIClient.h
//
//  Created by Joseph Lorich on 3/19/14.
//  Copyright (c) 2014 Joseph Lorich.
//  Contributions by Cloudspace (http://www.cloudspace.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#import <Foundation/Foundation.h>

#pragma mark - Block definitions

/// An APIKit request success block
typedef void (^APISuccessBlock)(id responseObject, NSInteger httpStatus);

/// An APIKit request failure block
typedef void (^APIFailureBlock)(id responseObject, NSInteger httpStatus, NSError *error);


#pragma mark - Enumerations

/// Each available request serialization type
typedef NS_ENUM(NSInteger, APISerializationType) {
    APIJSONSerialization,
    APIFormSerialization,
    APIPropertyListSerialization
};


#pragma mark - APIClient Interface

/**
 * A client interface to an API
 */
@interface APIClient : NSObject


#pragma mark - Properties

/// The HTTP Authorization header bearer token to be appended to outgoing requests
@property (nonatomic, retain) NSString *authorizationBearerToken;

/// The method of serialization for each request
@property APISerializationType requestSerializationType;


#pragma mark - Class methods

/**
 * Returns a shared APIClient instance
 */
+ (APIClient *) shared;

/**
 * Sets the singleton API client object
 * @param sharedClient The new shared UWAPIClient object
 */
+ (void)setSharedClient:(APIClient*)sharedClient;


#pragma mark - Instance methods

/**
 * Makes a request to a named route
 *
 * @param routeName The route name to use for this request
 * @param parameters The params to use in the API request
 * @param success The block to be executed on request success
 * @param failure The block to be executed on request failure
 */
- (void) requestRoute:(NSString *)routeName
           parameters:(NSDictionary *)parameters
              success:(APISuccessBlock)success
              failure:(APIFailureBlock)failure;

/**
 * Makes a request to a direct full URL, treating it as route "routeName"
 */
- (void)requestURL:(NSURL *)url asRoute:(NSString *)routeName parameters:(NSDictionary *)parameters success:(APISuccessBlock)success failure:(APIFailureBlock)failure;

/**
 * Cancels all pending requests to given route
 *
 * @param routeName The route name to cancel requests by
 * @param parameters The params to used to build the url to be cancelled
 */
- (void)cancelOperationsForRoute:(NSString *)routeName  parameters:(NSDictionary *)parameters;

/**
 * Sets the value for the HTTP headers set in request objects made by the HTTP client. If `nil`, removes the existing value for that header.
 *
 * @param field The HTTP header to set a default value for
 * @param value The value set as default for the specified header, or `nil`
 */
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

/**
 * Returns the value for the HTTP headers set in the request serializer.
 *
 * @param field The HTTP header to retrieve the default value for
 *
 * @return The value set as default for the specified header, or `nil`
 */
- (NSString *)valueForHTTPHeaderField:(NSString *)field;

@end
