# JhForm
JhForm - 自定义表单工具类,可以更加简单,快捷的创建表单<br> 
<br> 
<br> 
<br> 
<br> 



<img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_00.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_01_1.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_01.gif" width="208" height="404">
<img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_02.gif" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_03_1.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_03.gif" width="208" height="404">
<img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_04.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_05.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_06.png" width="208" height="404">
<img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_06.gif" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_07.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_01_dark.png" width="208" height="404"><img src="https://gitee.com/iotjh/Picture/raw/master/FormDemo/form_demo_08.png" width="208" height="404">




## 更新说明


* 2020.10.23 - HXPhotoPicker更新至v3.1.2版本(iPhone12适配)，增加提交按钮相关属性<br>
* 2020.10.15 - 添加版本号v1.0.0，HXPhotoPicker更新至v3.1.1版本,处理iOS14图片异常<br>
* 2020.09.30 - 添加cell文字居中效果 <br>
* 2020.08.05 - JhFormSelectImageCell优化 <br>
* 2020.07.24 - JhFormSelectImageCell高度自适应，无加号按钮 优化 <br>
* 2020.04.28 - HXPhotoPicker更新至v2.4.2版本，JhFormSelectImageCell高度自适应 <br>
* 2020.01.14 - 优化图片动态更新 <br>
* 2019.10.16 - 适配iOS13暗黑模式(默认跟随系统自动切换,可控制某个页面一直处于light模式) <br>
* 2019.09.30 - 添加设置标题颜色属性,添加设置cell不可编辑的属性,添加一些备用字段,修改cell重用的逻辑<br>
* 2019.09.12 - 修复存在多个相同类型iuputCell右侧自定义view复用的问题<br>
* 2019.09.11 - 文本输入和密码输入样式增加右侧自定义View,新增只显示右侧输入框样式(设置Jh_title为空即可),标题增加换行展示,选择图片cell增加底部提示文本(不设置默认不显示),优化红星展示方式 <br> 
* 2019.07.26 - 新增完全自定义样式cell (JhFormCustumALLViewCell) ,添加cell背景色设置属性 "Jh_cellBgColor"<br> 
* 2019.06.21 - 新增密码输入样式cell (JhFormPwdCell) <br> 
* 2019.06.18 - 修复switchBtn开关失效的问题 <br> 
* 2019.04.22 - 添加统一设置标题宽度的属性 "Jh_leftTitleWidth" <br> 
* 2019.04.18 - 添加单个设置标题宽度的属性 "Jh_titleWidth" <br> 
* 2019.04.02 - 添加选择最大图片数量属性 <br> 
* 2019.03.27 - CustumRightCell样式添加显示箭头的属性 <br> 
* 2019.03.22 - 新增设置导航条右侧文字和图片的方法,添加快捷添加输入样式cell的方法,监听输入文字和输入完成状态的Block <br> 


## Examples


* 特别提醒:
```
好多地方用到Block,认真检查是否用的弱引用,否则会造成内存泄露

```

* 样式1 - 输入样式
```
     //默认文本居左可编辑
    JhFormCellModel *cell4 = JhFormCellModel_AddInputCell(@"手机号:", @"XXX(可编辑)", YES, UIKeyboardTypePhonePad);
    cell4.Jh_placeholder = @"请输入手机号(最长11位,必选)";
    cell4.Jh_maxInputLength = 11;
    cell4.JhInputBlock = ^(NSString *text, BOOL isInputCompletion) {
        NSLog(@" 监听输入的文字 %@ ",text);
        BOOL boolValue = isInputCompletion;
        NSLog(@"是否输入完成%@", boolValue ? @"YES" : @"NO");
      };

```

* 样式2 - 选择样式
```

    JhFormCellModel *cell5 = JhFormCellModel_AddSelectCell(@"性别:", @"文本居左(可选择)", YES);
    cell5.Jh_placeholder = @"请选择性别";
    __weak typeof(cell5) weakCell5 = cell5;
    cell5.Jh_CellSelectCellBlock = ^(JhFormCellModel *cellModel) {
        //1.使用自己熟悉的选择弹框 ,选择完成对 Jh_info 赋值 (需要对应ID的话对Jh_info_idStr 赋值 )
        //2. 刷新 [weakSelf.Jh_formTableView reloadData];
    };


```
* 样式3 - textView
```
        JhFormCellModel *cell6 = JhFormCellModel_Add(@"备注:", @"默认备注", JhFormCellTypeTextViewInput, YES, YES, UIKeyboardTypeDefault);
    cell6.Jh_placeholder = @"请输入备注(最多50字)";
    cell6.Jh_showLength = YES;//默认不显示
    cell6.Jh_maxInputLength = 50;

```

* 样式4 - 默认选择图片样式
```
      JhFormCellModel *cell7 = JhFormCellModel_AddImageCell(@"选择图片:", NO);

```

* 样式5 - switch样式
```
        JhFormCellModel *cell2 = JhFormCellModel_AddSwitchBtnCell(@"左标题:", YES);
    cell2.Jh_switchTintColor = [UIColor orangeColor];
    
    //可以不通过block获取开关状态
    __weak typeof(cell2) weakCell2 = cell2;
    cell2.Jh_switchBtnBlock = ^(BOOL switchBtn_on, UISwitch *switchBtn) {
        NSLog(@"switchBtn_on %@", switchBtn_on ? @"YES" : @"NO");
//        weakCell2.Jh_switchOnTintColor = JhRandomColor;
        [weakSelf.Jh_formTableView reloadData];
    };


```

* 样式6 - 文本居右
```
  JhFormCellModel *cell0 = JhFormCellModel_AddRightTextCell(@"左标题:", @"右信息(不可编辑,居右)");

```
* 样式7 - 文本居右带箭头
```
  JhFormCellModel *cell1 = JhFormCellModel_AddRightArrowCell(@"左标题:", @"右信息(居右,带箭头)");

```

* 样式8 - 右侧自定义View
```
  //右侧自定义View
    UIView *rightView = [[UIView alloc]init];
    rightView.backgroundColor = JhRandomColor;

    
    JhFormCellModel *cell0 = JhFormCellModel_AddCustumRightCell(@"右侧自定义:");
    cell0.Jh_defaultHeight = 60;
    cell0.Jh_custumRightViewBlock = ^(UIView *RightView) {
        [RightView  addSubview:rightView];
        [rightView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(0);
            make.left.mas_equalTo(0);
            make.bottom.mas_equalTo(0);
            make.right.mas_equalTo(0);
        }];
    };

```
* 样式9 - 底部自定义View
```

 //底部自定义View
    UIView *bottomView = [[UIView alloc]init];
    bottomView.backgroundColor = JhRandomColor;
    
    JhFormCellModel *cell1 = JhFormCellModel_AddCustumBottomCell(@"底部自定义:");
    cell1.Jh_defaultHeight = 200;
    cell1.Jh_custumBottomViewBlock = ^(UIView *BottomView) {
        [BottomView addSubview:bottomView];
        [bottomView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(0);
            make.left.mas_equalTo(0);
            make.bottom.mas_equalTo(0);
            make.right.mas_equalTo(0);
        }];
    };
    

```

   
  

* 样式10 - 文本居中
```
   
    //文本居中
    JhFormCellModel *Section1_cell1 = JhFormCellModel_AddCenterTextCell(@"退出登录");
    
    //设置头部
    JhBaseHeaderView *headerV = [[JhBaseHeaderView alloc] initWithFrame:CGRectMake(0, 0, Kwidth, 44)];
    headerV.backgroundColor = BaseBgWhiteColor;
    headerV.Jh_leftTitle = @"第一组头部";
    section0.Jh_headerView = headerV;
    section0.Jh_headerHeight= headerV.bounds.size.height;

```

* 样式11 - 密码输入样式
```
   
    JhFormCellModel *pwd = JhFormCellModel_AddPwdInputCell(@"旧密码:", @"", YES);
    pwd.Jh_placeholder = @"请输入旧密码";
    pwd.Jh_maxInputLength = 25;
    pwd.Jh_InfoTextAlignment =  JhFormCellInfoTextAlignmentRight; //默认居左
    pwd.Jh_keyboardType = UIKeyboardTypeNumberPad;
    pwd.JhInputBlock = ^(NSString * _Nonnull text, BOOL isInputCompletion) {
        NSLog(@"当前的输入状态: %@", isInputCompletion ? @"YES" : @"NO");
        NSLog(@"文字: %@", text);
    };

```

* 样式12 - 完全自定义样式
```
   
     JhFormCellModel *cell_allcustum = JhFormCellModel_AddCustumALLViewCell(80);
     cell_allcustum.Jh_cellBgColor = JhRandomColor; //完全自定义样式的cell 只有高度和背景颜色可以设置
      cell_allcustum.Jh_custumALLViewBlock = ^(UIView * _Nonnull AllView) {
        AllView.backgroundColor =[UIColor yellowColor];
        
        UILabel *label = [[UILabel alloc]init];
        label.backgroundColor =JhRandomColor;
        label.text =@"这是一个可以完全自定义的cell";
        label.frame=CGRectMake(0, 30, Kwidth-30, 20);
        [AllView addSubview:label];
        
    };

```

* 13 - 标题换行展示
```

    NSString *title= @"统一社会\n 信用代码";
    JhFormCellModel *cell6 = JhFormCellModel_AddInputCell(title, @"", YES, 0);
    cell6.Jh_placeholder = @"请输入18位统一社会信用代码";
    cell6.Jh_titleMultiLineShow =YES; //标题换行展示
    cell6.Jh_maxInputLength = 18;
```



*  一些其他的设置
```
   
     //隐藏默认的footerView
    self.Jh_defaultFooterViewHidden = YES;


    可隐藏整个页面的红星按只有标题显示
    self.Jh_leftTitleHiddenRedStar =YES;


    //暗黑模式切换: JhFormConst 中 Jh_ThemeType类型控制
 
    
#pragma mark - 设置导航条title和右侧文字
-(void)setNav{
    
    self.Jh_navTitle = @"表单Demo1 - 默认";
    self.Jh_navRightTitle =@"文字";
    self.JhClickNavRightItemBlock = ^{
        NSLog(@" 点击跳转 ");
    };
    
}


//提交按钮相关设置（当个页面），全局配置在JhFormConst文件中修改
self.Jh_submitBtnBgColor = [UIColor redColor]; //全局配置背景色要去修改BaseThemeColor
self.Jh_submitBtnTBSpace = 30;
self.Jh_submitBtnLRSpace = 100;
self.Jh_submitBtnHeight = 50;
self.Jh_submitBtnTextColor = [UIColor yellowColor];
self.Jh_submitBtnCornerRadius = 25.0;
self.Jh_submitBtnTextFontSize = 22;
//粗体
self.Jh_submitBtn.titleLabel.font = [UIFont fontWithName:@"Helvetica-Bold"size:30];
//边框
self.Jh_submitBtn.layer.borderWidth = 2;
self.Jh_submitBtn.layer.borderColor = [[UIColor grayColor] CGColor];
self.Jh_submitStr = @"提 交";


    

```


* 添加和提交的处理
```

     NSMutableArray *cellArr0 = [NSMutableArray array];
  
    [cellArr0 addObjectsFromArray: @[cell0,cell1,cell2,cell3,cell4,cell5,cell6,cell7]];
    
    JhFormSectionModel *section0 = JhSectionModel_Add(cellArr0);
    
    [self.Jh_formModelArr addObject:section0];
    
    self.Jh_submitStr = @"提 交";
    self.Jh_formSubmitBlock = ^{
        NSLog(@" 点击提交按钮 ");
        
        NSLog(@" cell0.Jh_info - %@", cell0.Jh_info);
        NSLog(@" cell1.Jh_info - %@", cell1.Jh_info);
        NSLog(@" cell2.开关的状态 - %@", cell2.Jh_switchBtn_on ? @"YES" : @"NO");
        NSLog(@" cell3.Jh_info - %@", cell3.Jh_info);
        NSLog(@" cell4.Jh_info - %@", cell4.Jh_info);
        NSLog(@" cell5.Jh_info - %@", cell5.Jh_info);
        NSLog(@" cell6.Jh_info - %@", cell6.Jh_info);
        NSLog(@" 选择图片类 - Jh_selectImageArr: %@ ",cell6.Jh_selectImageArr);
        
        // 这里只是简单描述校验逻辑，可根据自身需求封装数据校验逻辑
        [JhFormHandler Jh_checkFormNullDataWithWithDatas:weakSelf.Jh_formModelArr success:^{
            
            [weakSelf SubmitRequest];
            
        } failure:^(NSString *error) {
            NSLog(@"error====%@",error);
//            [JhProgressHUD showText:error];
        }];
        
    };
    
    

```


### 特别感谢：RockChanel<br> 
[SWForm代码地址](https://github.com/RockChanel/SWForm)<br> 


