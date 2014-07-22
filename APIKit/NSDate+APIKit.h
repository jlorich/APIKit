//
//  NSDate+APIKit.h
//  Pods
//
//  Created by Joseph Lorich on 7/22/14.
//
//

#import <Foundation/Foundation.h>

@interface NSDate (APIKit)

/**
 * Parses an NSDate out of an api date string
 *
 * @param dateString the api date string to parse
 */
+ (NSDate *)dateFromAPIDateString:(NSString*)dateString;

/**
 * Format an NSDate to a ruby api compliant string
 *
 * @param date The date to format
 */
+ (NSString *)apiStringFromDate:(NSDate *)date;

/**
 * Format this date to a ruby api compliant string
 */
- (NSString *)toAPIString;



@end
