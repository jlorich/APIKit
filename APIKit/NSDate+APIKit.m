//
//  NSDate+APIKit.m
//  Pods
//
//  Created by Joseph Lorich on 7/22/14.
//
//

#import "NSDate+APIKit.h"

@implementation NSDate (APIKit)

-(NSDate *) toLocalTime
{
    NSTimeZone *tz = [NSTimeZone defaultTimeZone];
    NSInteger seconds = [tz secondsFromGMTForDate: self];
    return [NSDate dateWithTimeInterval: seconds sinceDate: self];
}

-(NSDate *) toGlobalTime
{
    NSTimeZone *tz = [NSTimeZone defaultTimeZone];
    NSInteger seconds = -[tz secondsFromGMTForDate: self];
    return [NSDate dateWithTimeInterval: seconds sinceDate: self];
}

+ (NSDate *)dateFromAPIDateString:(NSString*)dateString
{
    NSString *dateFormat = [self apiDateFormatForDateString:dateString];
    
    return [self adjustedDateFromAPIDateString:dateString toZone:[NSTimeZone timeZoneWithName:@"UTC"] withFormat:dateFormat];
}

+ (NSDate *)adjustedDateFromAPIDateString:(NSString*)dateString toZone:(NSString *)timeZoneName {
  NSString *dateFormat = [self apiDateFormatForDateString:dateString];
  NSTimeZone *zone = [NSTimeZone timeZoneWithName:timeZoneName];
 
  return [self adjustedDateFromAPIDateString:dateString toZone:zone withFormat:dateFormat];
}

+ (NSDate *)adjustedDateFromAPIDateString:(NSString*)dateString toZone:(NSTimeZone *)timeZone withFormat:(NSString *)format {
    if (!dateString) { return nil; }

    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    
    [dateFormatter setTimeZone:timeZone];
    [dateFormatter setDateFormat:format];
    
    return [dateFormatter dateFromString:dateString];
}

+ (NSString *)apiStringFromDate:(NSDate *)date {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd"];
    
    [formatter setTimeZone:[NSTimeZone localTimeZone]];
    
    return [formatter stringFromDate:date];
}

- (NSString *)toAPIString {
    return [NSDate apiStringFromDate:self];
}

+ (NSString *)apiDateFormatForDateString:(NSString *)dateString {
    if (dateString == nil) {
        return @"";
    } else if([dateString rangeOfString:@" "].location != NSNotFound) {
        return @"yyyy-MM-dd'T'HH:mm:ss.SSS Z";
    } else if ([dateString rangeOfString:@"T"].location != NSNotFound) {
        return @"yyyy-MM-dd'T'HH:mm:ss.SSS'Z'";
    } else {
        return @"yyyy-MM-dd";

    }
}


@end
