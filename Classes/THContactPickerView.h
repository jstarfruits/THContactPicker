//
//  ContactPickerTextView.h
//  ContactPicker
//
//  Created by Tristan Himmelman on 11/2/12.
//  Copyright (c) 2012 Tristan Himmelman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "THContactBubble.h"

@class THContactPickerView;

@protocol THContactPickerDelegate <NSObject>

- (void)contactPickerTextViewDidChange:(NSString *)textViewText;
- (void)contactPickerDidRemoveContact:(id)contact;
- (void)contactPickerDidResize:(THContactPickerView *)contactPickerView;
- (BOOL)contactPickerTextFieldShouldReturn:(UITextField *)textField;

@end

@interface THContactPickerView : UIView <UITextViewDelegate, THContactBubbleDelegate, UIScrollViewDelegate, UITextInputTraits>

@property (nonatomic, strong) THContactBubble *selectedContactBubble;
@property (nonatomic, assign) IBOutlet id <THContactPickerDelegate>delegate;

@property (nonatomic, assign) BOOL limitToOne;				// only allow the ContactPicker to add one contact
@property (nonatomic, assign) CGFloat verticalPadding;		// amount of padding above and below each contact bubble
@property (nonatomic, assign) NSInteger maxNumberOfLines;	// maximum number of lines the view will display before scrolling
@property (nonatomic, strong) UIFont *font;

- (void)addContact:(id)contact withName:(NSString *)name;
- (void)removeContact:(id)contact;
- (void)removeAllContacts;
- (void)resignFirstResponder;

// View Customization
- (void)setBubbleStyle:(THBubbleStyle *)color selectedStyle:(THBubbleStyle *)selectedColor;
- (void)setPlaceholderLabelText:(NSString *)text;
- (void)setPlaceholderLabelTextColor:(UIColor *)color;
- (void)setPromptLabelText:(NSString *)text;
- (void)setPromptLabelTextColor:(UIColor *)color;
- (void)setFont:(UIFont *)font;

@end