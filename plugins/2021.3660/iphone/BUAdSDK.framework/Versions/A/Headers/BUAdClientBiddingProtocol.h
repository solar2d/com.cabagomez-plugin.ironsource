//
//  BUAdClientBiddingProtocol.h
//  Pods
//
//  Created by bytedance on 2021/9/14.
//

#import <Foundation/Foundation.h>

@protocol BUAdClientBiddingProtocol <NSObject>

@optional

/// invoke this method to set this actual auction price 调用此方法设置当前实际结算价
/// @param auctionPrice auction price 实际结算价格
- (void)setPrice:(nullable NSNumber *)auctionPrice;

/// invoke this method when the bidding  succeeds (strongly recommended)  当竞价成功调用此方法(强烈推荐)
/// @param auctionBidToWin the seccond place bidder's price 竞价方第二名的价格
- (void)win:(nullable NSNumber*)auctionBidToWin;

/// invoke this method when the bidding  fails (strongly recommended)  当竞价失败调用此方法(强烈推荐)
/// @param auctionPrice auction price  竞价
/// @param lossReason Reasons for failed bidding 失败的原因
/// @param winBidder Who won the bid 谁赢了竞价
- (void)loss:(nullable NSNumber*)auctionPrice lossReason:(nullable NSString*)lossReason winBidder:(nullable NSString*)winBidder;

@end
