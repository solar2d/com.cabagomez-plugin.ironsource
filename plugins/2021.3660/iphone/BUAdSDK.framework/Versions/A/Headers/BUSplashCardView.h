//
//  BUSplashCardView.h
//  BUAdSDK
//
//  Created by ByteDance on 2022/3/23.
//

#import <UIKit/UIKit.h>
#import "BUMaterialMeta.h"
#import "BUInterfaceBaseView.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BUSplashCardViewDelegate;

__attribute__((objc_subclassing_restricted))
@interface BUSplashCardView : BUInterfaceBaseView

@property (nonatomic, weak) id<BUSplashCardViewDelegate> delegate;
@property (nonatomic, weak) UIViewController *rootViewController;

- (void)showSplashCardInRootVC:(UIViewController *)rootVC;

@end


@protocol BUSplashCardViewDelegate <NSObject>
/**
 This method is called when splash card is clicked.
 */
- (void)splashCardViewAdDidClick:(BUSplashCardView *)splashCard;

/**
 This method is called when splash card is closed.
 */
- (void)splashCardViewAdDidClose:(BUSplashCardView *)splashCard;

/**
This method is called when spalash card automatically dimiss afte countdown equals to zero
*/
- (void)splashCardViewAdDidAutoDimiss:(BUSplashCardView *)splashCard;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)splashCardViewAdDidCloseOtherController:(BUSplashCardView *)splashCard interactionType:(BUInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END
