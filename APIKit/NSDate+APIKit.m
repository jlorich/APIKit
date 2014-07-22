//
//  NSDate+APIKit.m
//  Pods
//
//  Created by Joseph Lorich on 7/22/14.
//
//

#import "NSDate+APIKit.h"

@implementation NSDate (APIKit)

+ (NSDate *)dateFromAPIDateString:(NSString*)dateString
{
    // Ignore nil dates
    if (dateString == nil) return nil;
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    
    if ([dateString rangeOfString:@"T"].location == NSNotFound)
    {
        // Ain't nobody got time for that
        [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    }
    else
    {
        [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS'Z'"];
    }
    
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"UTC"]];
    
    return [dateFormatter dateFromString:dateString];
}

+ (NSString *)apiStringFromDate:(NSDate *)date {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd"];
    
    [formatter setTimeZone:[NSTimeZone timeZoneWithName:@"UTC"]];
    
    return [formatter stringFromDate:date];
}

- (NSString *)toAPIString {
    return [NSDate apiStringFromDate:self];
}


@end
