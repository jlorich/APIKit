//
//  NSDate+APIKit.h
//  Pods
//
//  Created by Joseph Lorich on 7/22/14.
//
//

#import <Foundation/Foundation.h>

@interface NSDate (APIKit)

-(NSDate *) toLocalTime;

-(NSDate *) toGlobalTime;


/**
 * Parses an NSDate out of an api date string
 *
 * @param dateString the api date string to parse
 */
+ (NSDate *)dateFromAPIDateString:(NSString*)dateString;

/**
 * Parses an NSDate out of an api date string and convert it to the local timezone (from the given zone)
 *
 * @param date The date to format
 * @param timeZoneName The name of the time zone the datestring is given in
 */
+ (NSDate *)adjustedDateFromAPIDateString:(NSString*)dateString toZone:(NSString *)timeZoneName;

/**
 * Parses an NSDate out of an api date string and convert it to the local timezone (from the given zone)
 *
 * @param date The date to format
 * @param timeZoneName The name of the time zone the datestring is given in
 * @param format The format to use to parse the date
 */
+ (NSDate *)adjustedDateFromAPIDateString:(NSString*)dateString toZone:(NSString *)timeZoneName withFormat:(NSString *)format;
    
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
