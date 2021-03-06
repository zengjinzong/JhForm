//
//  JhFormTableViewVC.h
//  JhForm
//
//  Created by Jh on 2019/1/4.
//  Copyright © 2019 Jh. All rights reserved.
//



#import <UIKit/UIKit.h>
#import "JhFormConst.h"
#import "HXPhotoPicker.h"
#import "JhFormCellModel.h"
#import "JhFormSectionModel.h"
#import "JhFormHandler.h"

NS_ASSUME_NONNULL_BEGIN


typedef void(^JhFormSubmitBlock)(void);

@interface JhFormTableViewVC : UIViewController

/**
 表单tableView
 */
@property (nonatomic, strong) UITableView *Jh_formTableView;

/** 标题 */
@property (nonatomic, strong) NSString *Jh_navTitle;

/** 导航栏右侧标题 */
@property (nonatomic, strong) NSString *Jh_navRightTitle;

/** 导航栏右侧img */
@property (nonatomic, strong) NSString *Jh_navRightImage;

/** 点击导航栏右侧item Block */
@property (nonatomic,   copy) void(^JhClickNavRightItemBlock)(void);

/** 提交按钮 */
@property (nonatomic, strong) UIButton *Jh_submitBtn;

/** 提交文字 */
@property (nonatomic, strong) NSString *Jh_submitStr;

/** 提交按钮背景色，单页面设置；全局配置修改BaseThemeColor  */
@property (nonatomic, strong) UIColor * Jh_submitBtnBgColor;

/** 表单提交按钮 上下间距   默认25（上25，下25） */
@property (nonatomic, assign) CGFloat  Jh_submitBtnTBSpace;

/** 表单提交按钮 左右间距   默认15（左15，右15） */
@property (nonatomic, assign) CGFloat  Jh_submitBtnLRSpace;

/** 表单提交按钮 圆角   默认5  */
@property (nonatomic, assign) CGFloat  Jh_submitBtnCornerRadius;

/** 表单提交按钮 高度   默认40  */
@property (nonatomic, assign) CGFloat  Jh_submitBtnHeight;

/** 表单提交按钮 文字大小 默认17 */
@property (nonatomic, assign) CGFloat  Jh_submitBtnTextFontSize;

/** 表单提交按钮 文字颜色，默认白色 */
@property (nonatomic, strong) UIColor *Jh_submitBtnTextColor;

/** 表单数据源，数据源格式应为 @[JhFormSection..]，否则断言会直接崩溃 */
@property (nonatomic, strong) NSMutableArray *Jh_formModelArr;

/** 提交操作事件block，包含提交操作表单页面提交按钮点击事件实现回调 */
@property (nonatomic,   copy) JhFormSubmitBlock Jh_formSubmitBlock;

/** 隐藏默认的footerView */
@property (nonatomic, assign) BOOL Jh_hiddenDefaultFooterView;

/** 统一配置cell左侧title的宽度(默认100) */
@property (nonatomic, assign) CGFloat Jh_leftTitleWidth;

/** 可隐藏整个页面的红星按只有标题显示 */
@property (nonatomic, assign) CGFloat Jh_leftTitleHiddenRedStar;

/** 设置主题为light(不跟随系统设置切换 ,iOS13生效) */
@property (nonatomic, assign) BOOL Jh_useLightTheme;


@end

NS_ASSUME_NONNULL_END
