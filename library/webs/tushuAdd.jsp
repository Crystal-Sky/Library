<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>图书捐赠系统</title>
    <meta http-equiv="X-UA-Compatible" content="IE=8">
    <link rel="stylesheet" type="text/css" href="staticFiles/tushu/style/gift.css">
    <script src="staticFiles/xinan/js/jquery-1.4.4.min.js" language="javascript"></script>
    <script src="js/NewCalendar.js" language="javascript"></script>
    <link href="kindeditor/themes/default/default.css" rel="stylesheet">
</head>
<body>
<div id="ContainerPanel" style="display:none;">
    <div id="calendarPanel"
         style="position: absolute;display: none;z-index: 9999;background-color: #FFFFFF;border: 1px solid #CCCCCC;width:175px;font-size:12px;"></div>
</div>
<script type="text/javascript" charset="utf-8" src="kindeditor/kindeditor.js"></script>
<script type="text/javascript">
    KindEditor.ready(function (K) {
        editor1 = K.create('textarea[id="content1"]', {
            cssPath: '/kindeditor/plugins/code/prettify.css',
            uploadJson: '/admin/kindeditor_uploadFile.action',
            fileManagerJson: '/kindeditor/jsp/file_manager_json.jsp',
            allowFileManager: true,
            afterCreate: function () {
                var self = this;
                K.ctrl(document, 13, function () {
                    self.sync();
                    document.forms['addnews'].submit();
                });
                K.ctrl(self.edit.doc, 13, function () {
                    self.sync();
                    document.forms['addnews'].submit();
                });
            }
        });
        //prettyPrint();
    });

    function beforess() {

        var jzname = document.getElementById("newsUn_title").value;
        jzname = jzname.replace(/\s/g, '');
        if (jzname == "") {
            alert("请输入捐赠名项!");
            return false;
        }

        var phoneNum = document.getElementById("newsUn_phoneNum").value;
        phoneNum = phoneNum.replace(/\s/g, '');

        if (phoneNum != "") {
            var p1 = /^((0\d{2,3})-)?(\d{7,8})$/;
            var p2 = /^1[3|5][0-9]\d{4,8}$/;
            if (p1.test(phoneNum) || p2.test(phoneNum)) {
                return true;
            } else {
                alert("请输入合法的手机或电话号码!\r\n如果是电话号码，请按格式输入\r\n正确格式：区号-座机号");
                document.getElementById("newsUn_phoneNum").select();
                return false;
            }
        }
        return true;
    }
</script>


<div class="wrap">
    <div class="header">
        <img src="staticFiles/tushu/images/tushujuanzeng.jpg">
    </div>
    <div class="main clearfix">
        <div class="left leftside">
            <div class="news">
                <div class="newsHd">
                    <b>您当前的位置是：</b><a href="/">图书馆首页</a> &gt;&gt; <a target="_self"
                                                                     href="webs/newsUn_toTushu.action?toUrl=tushu">图书捐赠首页</a>
                    &gt;&gt;图书捐赠
                </div>
                <div class="newsBd" style="padding-left:50px;">
                    <form name="addnews" method="post" action="webs/newsUn_newsUnAdd.action"
                          onsubmit="return beforess();">
                        <table class="t_news" width="716" border="0" cellspacing="0" cellpadding="0">
                            <tbody>
                            <tr height="30">
                                <td colspan="3" style="text-align: center;font-size: 16px;font-weight: bolder;">图书捐赠
                                </td>
                            </tr>
                            <input type="hidden" name="toUrl" value="tsnotice">
                            <tr height="30">
                                <td width="160">捐赠名项:</td>
                                <td width="500"><input type="text" name="newsUn.title" size="50" value=""
                                                       id="newsUn_title"></td>
                                <td width="200" id="title_ret" style="color:#F00">&nbsp;</td>
                            </tr>
                            <tr height="30">
                                <td>捐&nbsp;赠&nbsp;者:</td>
                                <td width="500">
                                    <input type="text" size="50" name="newsUn.userName">
                                </td>
                                <td width="200">&nbsp;</td>
                            </tr>
                            <tr height="30">
                                <td>捐赠者联系电话:</td>
                                <td><input maxlength="12" type="text" size="50" name="newsUn.phoneNum"
                                           id="newsUn_phoneNum"></td>
                                <td id="phone_ret" style="color:#F00">&nbsp;</td>
                            </tr>
                            <tr height="30">
                                <td>捐赠者类型:</td>
                                <td>
                                    <select name="newsUn.userType">
                                        <option value="社会人士">社会人士</option>
                                        <option value="毕业生">毕业生</option>
                                        <option value="在校生">在校生</option>
                                        <option value="老师">老师</option>
                                    </select>
                                </td>
                                <td>&nbsp;</td>
                            </tr>
                            <tr height="30">
                                <td>捐赠日期:</td>
                                <td><input type="text" name="newsUn.inserttime" size="10" value=""
                                           id="newsUn_inserttime" onclick="SelectDate(this,'yyyy-MM-dd');"></td>
                                <td>&nbsp;</td>
                            </tr>
                            <tr height="30">
                                <td>捐赠数量:</td>
                                <td><input type="text" name="newsUn.bookCount" size="50" maxlength="8" value="1"
                                           id="newsUn_bookCount" onkeyup="this.value=this.value.replace(/\D/g,'')"
                                           onafterpaste="this.value=this.value.replace(/\D/g,'')"></td>
                                <td>&nbsp;</td>
                            </tr>
                            <input type="hidden" name="newsUn.cataid" value="44">
                            <tr height="30">
                                <td>备&nbsp;&nbsp;&nbsp;注:</td>
                                <td colspan="2">
                                    <div class="ke-container ke-container-default" style="width: 619px;">
                                        <div style="display:block;" class="ke-toolbar" unselectable="on"><span
                                                class="ke-outline" data-name="source" title="HTML代码"
                                                unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-source"
                                                unselectable="on"></span></span><span
                                                class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                  data-name="undo"
                                                                                                  title="后退(Ctrl+Z)"
                                                                                                  unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-undo"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="redo"
                                                                                      title="前进(Ctrl+Y)"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-redo"
                                                unselectable="on"></span></span><span
                                                class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                  data-name="preview"
                                                                                                  title="预览"
                                                                                                  unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-preview"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="print"
                                                                                      title="打印(Ctrl+P)"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-print"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="template" title="插入模板"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-template"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="code" title="插入程序代码"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-code"
                                                unselectable="on"></span></span><span class="ke-outline" data-name="cut"
                                                                                      title="剪切(Ctrl+X)"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-cut"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="copy"
                                                                                      title="复制(Ctrl+C)"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-copy"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="paste"
                                                                                      title="粘贴(Ctrl+V)"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-paste"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="plainpaste"
                                                                                      title="粘贴为无格式文本"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-plainpaste"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="wordpaste"
                                                                                      title="从Word粘贴" unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-wordpaste"
                                                unselectable="on"></span></span><span
                                                class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                  data-name="justifyleft"
                                                                                                  title="左对齐"
                                                                                                  unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-justifyleft"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="justifycenter"
                                                                                      title="居中" unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-justifycenter"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="justifyright"
                                                                                      title="右对齐"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-justifyright"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="justifyfull"
                                                                                      title="两端对齐"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-justifyfull"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="insertorderedlist"
                                                                                      title="编号" unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-insertorderedlist"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="insertunorderedlist"
                                                                                      title="项目符号"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-insertunorderedlist"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="indent" title="增加缩进"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-indent"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="outdent" title="减少缩进"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-outdent"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="subscript" title="下标"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-subscript"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="superscript" title="上标"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-superscript"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="clearhtml"
                                                                                      title="清理HTML代码"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-clearhtml"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="quickformat"
                                                                                      title="一键排版"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-quickformat"
                                                unselectable="on"></span></span><span class="ke-outline"
                                                                                      data-name="selectall"
                                                                                      title="全选(Ctrl+A)"
                                                                                      unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-selectall"
                                                unselectable="on"></span></span><span
                                                class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                  data-name="fullscreen"
                                                                                                  title="全屏显示(Esc)"
                                                                                                  unselectable="on"><span
                                                class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-fullscreen"
                                                unselectable="on"></span></span>
                                            <div class="ke-hr"></div>
                                            <span class="ke-outline" data-name="formatblock" title="段落"
                                                  unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-formatblock"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="fontname"
                                                                                          title="字体"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-fontname"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="fontsize"
                                                                                          title="文字大小"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-fontsize"
                                                    unselectable="on"></span></span><span
                                                    class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                      data-name="forecolor"
                                                                                                      title="文字颜色"
                                                                                                      unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-forecolor"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="hilitecolor"
                                                                                          title="文字背景"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-hilitecolor"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="bold"
                                                                                          title="粗体(Ctrl+B)"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-bold"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="italic"
                                                                                          title="斜体(Ctrl+I)"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-italic"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="underline"
                                                                                          title="下划线(Ctrl+U)"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-underline"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="strikethrough"
                                                                                          title="删除线" unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-strikethrough"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="lineheight"
                                                                                          title="行距"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-lineheight"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="removeformat"
                                                                                          title="删除格式"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-removeformat"
                                                    unselectable="on"></span></span><span
                                                    class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                      data-name="image"
                                                                                                      title="图片"
                                                                                                      unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-image"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="multiimage"
                                                                                          title="批量图片上传"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-multiimage"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="flash"
                                                                                          title="Flash"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-flash"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="media" title="视音频"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-media"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="insertfile"
                                                                                          title="插入文件"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-insertfile"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="table" title="表格"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-table"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="hr" title="插入横线"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-hr"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="emoticons"
                                                                                          title="插入表情"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-emoticons"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="baidumap"
                                                                                          title="百度地图"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-baidumap"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="pagebreak"
                                                                                          title="插入分页符"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-pagebreak"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="anchor" title="锚点"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-anchor"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="link" title="超级链接"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-link"
                                                    unselectable="on"></span></span><span class="ke-outline"
                                                                                          data-name="unlink"
                                                                                          title="取消超级链接"
                                                                                          unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-unlink"
                                                    unselectable="on"></span></span><span
                                                    class="ke-inline-block ke-separator"></span><span class="ke-outline"
                                                                                                      data-name="about"
                                                                                                      title="关于"
                                                                                                      unselectable="on"><span
                                                    class="ke-toolbar-icon ke-toolbar-icon-url ke-icon-about"
                                                    unselectable="on"></span></span></div>
                                        <div style="display: block; height: 194px;" class="ke-edit">
                                            <iframe class="ke-edit-iframe" hidefocus="true" frameborder="0"
                                                    style="width: 100%; height: 194px;"></iframe>
                                            <textarea class="ke-edit-textarea" hidefocus="true"
                                                      style="width: 100%; height: 194px; display: none;"></textarea>
                                        </div>
                                        <div class="ke-statusbar"><span
                                                class="ke-inline-block ke-statusbar-center-icon"></span><span
                                                class="ke-inline-block ke-statusbar-right-icon"></span></div>
                                    </div>
                                    <textarea id="content1" name="newsUn.des" cols="100" rows="6"
                                              style="height: 300px; visibility: hidden; display: none;">												</textarea>
                                </td>
                            </tr>
                            <tr height="30">
                                <td>&nbsp;</td>
                                <td><input type="submit" value="提交">&nbsp;<input type="reset" value="重置"></td>
                                <td>&nbsp;</td>
                            </tr>
                            </tbody>
                        </table>

                    </form>
                </div>
            </div>
        </div>

        <div class="right rightside">
            <a target="_blank" href="webs/newsUn_toHome.action?toUrl=tsXuzhi" class="notice"></a>
            <div class="column search">
                <div class="columnHd">
                    捐赠信息检索
                </div>
                <div class="columnBd">
                    <form name="form1" method="post" action="webs/newsUn_newsUnSearch.action">
                        <table width="100%">
                            <tbody>
                            <tr>
                                <th>
                                    捐赠人：
                                </th>
                                <td>
                                    <input type="text" class="field" name="newsUn.userName">
                                    <input type="hidden" name="toUrl" value="tsSearch">
                                    <input type="hidden" name="newsUn.cataid" value="44">
                                    <input type="hidden" name="pagesize" value="20">
                                </td>
                            </tr>
                            <tr>
                                <th>
                                    捐赠标题：
                                </th>
                                <td>
                                    <input type="text" class="field" name="newsUn.title">
                                </td>
                            </tr>
                            <tr>
                                <td colspan="2" class="center">
                                    <input type="submit" value="">
                                    <input type="reset" style="background-position:0px -24px;" value="">
                                </td>
                            </tr>
                            </tbody>
                        </table>
                    </form>
                </div>
            </div>
        </div>
    </div>

    <div class="footer">
        版权所有 太原工业学院图书馆
        <br>
        Copyright © 2012 Taiyuangongye University Library.
    </div>
</div>
</body>
</html>