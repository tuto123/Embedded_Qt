#include "weatherquery.h"
#include "ui_weatherquery.h"

#include "mainwindow.h"

#include "common.h"

WeatherQuery::WeatherQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherQuery)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish_weather_que(QNetworkReply*))); //关联请求完成请求信号和finish_weather_que

    InitWindow();
}

WeatherQuery::~WeatherQuery()
{
    delete ui;
}

//给界面添加可以缩放背景图片
void WeatherQuery::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);          //背景图片透明度
    myPainter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/rec/img/sunny.png"));

}
void WeatherQuery::on_home_pushButton_clicked()
{
    this->close();
    MainWindow *mw = new MainWindow;
    mw->show();
}

//初始化Weather_que界面
void WeatherQuery::InitWindow()
{
    ui->weather_que_city_comboBox->insertItem(0, "梅州");

    weather_que();
}

//天气查询_pushButton
void WeatherQuery::on_weather_que_pushButton_clicked()
{
    weather_que();
}

//天气查询功能
void WeatherQuery::weather_que()
{
    que_city = ui->weather_que_city_comboBox->currentText(); //获得需要查询天气的城市名称
    weather_website = "http://wthrcdn.etouch.cn/weather_mini?city=";
    weather_website += que_city;
    weather_que_req.setUrl(QUrl(weather_website));
    weather_que_req.setHeader(QNetworkRequest::UserAgentHeader, "RT-Thread ART");

    manager->get(weather_que_req);  //发送get网络请求
}

//解析weather_website返回的天气Json数据
void WeatherQuery::finish_weather_que(QNetworkReply *reply)
{
     QString all = reply->readAll();

     QJsonParseError err;
     QJsonDocument json_recv = QJsonDocument::fromJson(all.toUtf8(), &err);//解析json对象

     if (!json_recv.isNull())
     {
        QJsonObject object = json_recv.object();

        if (object.contains("data"))
        {
            QJsonValue value = object.value("data");  // 获取指定 key 对应的 value
            if (value.isObject())
            {
                QJsonObject object_data = value.toObject();
                if (object_data.contains("forecast"))
                {
                    QJsonValue value = object_data.value("forecast");
                    if (value.isArray())
                    {
                        QJsonObject today_weather = value.toArray().at(0).toObject();
                        weather = today_weather.value("type").toString();

                        advice = object.value("data").toObject().value("ganmao").toString();
                        QString low = today_weather.value("low").toString();
                        QString high = today_weather.value("high").toString();

                        temperture = low.mid(low.length() - 3, 4) + "~" + high.mid(high.length() - 3, 4);

                        QString strength = today_weather.value("fengli").toString();
                        strength.remove(0, 8);
                        strength.remove(strength.length() - 2, 2);
                        wind = today_weather.value("fengxiang").toString() + strength;

                        ui->city_label->setText(ui->weather_que_city_comboBox->currentText());    //显示查询的城市
                        ui->weather_label->setText(weather);        //显示天气类型
                        ui->temperture_label->setText(temperture);  //显示温度
                        ui->wind_label->setText(wind);              //显示风力
                        ui->advice_label->setText(advice);          //显示推荐
                     }
                }
            }
        }

    }
    else
    {
        QMessageBox::about(NULL, "提示", "查询天气失败!");
    }
    reply->destroyed(); //销毁请求对象
}

//按条件查询城市
void WeatherQuery::on_ch_que_city_comboBox_activated(const QString &arg1)
{
    ui->weather_que_city_comboBox->clear();

        if(arg1 == "当前城市")
        {
            ui->weather_que_city_comboBox->insertItem(0, "梅州");
        }
        else if(arg1 == "热门")
        {
            ui->weather_que_city_comboBox->insertItem(0,  "北京");
            ui->weather_que_city_comboBox->insertItem(1,  "上海");
            ui->weather_que_city_comboBox->insertItem(2,  "广州");
            ui->weather_que_city_comboBox->insertItem(3,  "深圳");
            ui->weather_que_city_comboBox->insertItem(4,  "成都");
            ui->weather_que_city_comboBox->insertItem(5,  "杭州");
            ui->weather_que_city_comboBox->insertItem(6,  "西安");
            ui->weather_que_city_comboBox->insertItem(7,  "重庆");
            ui->weather_que_city_comboBox->insertItem(8,  "青岛");
            ui->weather_que_city_comboBox->insertItem(9,  "南京");
            ui->weather_que_city_comboBox->insertItem(10, "厦门");
            ui->weather_que_city_comboBox->insertItem(11, "昆明");
            ui->weather_que_city_comboBox->insertItem(12, "大连");
            ui->weather_que_city_comboBox->insertItem(13, "天津");
            ui->weather_que_city_comboBox->insertItem(14, "郑州");
            ui->weather_que_city_comboBox->insertItem(15, "三亚");
            ui->weather_que_city_comboBox->insertItem(16, "济南");
            ui->weather_que_city_comboBox->insertItem(17, "福州");
        }
        else if(arg1 == "ABCDE")
        {
            ui->weather_que_city_comboBox->insertItem(0,  "阿尔山");
            ui->weather_que_city_comboBox->insertItem(1,  "阿克苏");
            ui->weather_que_city_comboBox->insertItem(2,  "阿拉善右旗");
            ui->weather_que_city_comboBox->insertItem(3,  "阿拉善左旗");
            ui->weather_que_city_comboBox->insertItem(4,  "阿勒泰");
            ui->weather_que_city_comboBox->insertItem(5,  "阿里");
            ui->weather_que_city_comboBox->insertItem(6,  "澳门");
            ui->weather_que_city_comboBox->insertItem(7,  "安庆");
            ui->weather_que_city_comboBox->insertItem(8,  "安顺");
            ui->weather_que_city_comboBox->insertItem(9,  "鞍山");
            ui->weather_que_city_comboBox->insertItem(10, "巴彦淖尔");
            ui->weather_que_city_comboBox->insertItem(11, "百色");
            ui->weather_que_city_comboBox->insertItem(12, "包头");
            ui->weather_que_city_comboBox->insertItem(13, "保山");
            ui->weather_que_city_comboBox->insertItem(14, "北海");
            ui->weather_que_city_comboBox->insertItem(15, "北京");
            ui->weather_que_city_comboBox->insertItem(16, "白城");
            ui->weather_que_city_comboBox->insertItem(17, "白山");
            ui->weather_que_city_comboBox->insertItem(18, "毕节");
            ui->weather_que_city_comboBox->insertItem(19, "博乐");
            ui->weather_que_city_comboBox->insertItem(20, "重庆");
            ui->weather_que_city_comboBox->insertItem(21, "昌都");
            ui->weather_que_city_comboBox->insertItem(22, "常德");
            ui->weather_que_city_comboBox->insertItem(23, "常州");
            ui->weather_que_city_comboBox->insertItem(24, "朝阳");
            ui->weather_que_city_comboBox->insertItem(25, "成都");
            ui->weather_que_city_comboBox->insertItem(26, "池州");
            ui->weather_que_city_comboBox->insertItem(27, "赤峰");
            ui->weather_que_city_comboBox->insertItem(28, "揭阳");
            ui->weather_que_city_comboBox->insertItem(29, "长春");
            ui->weather_que_city_comboBox->insertItem(30, "长沙");
            ui->weather_que_city_comboBox->insertItem(31, "长治");
            ui->weather_que_city_comboBox->insertItem(32, "承德");
            ui->weather_que_city_comboBox->insertItem(33, "沧源");
            ui->weather_que_city_comboBox->insertItem(34, "达县");
            ui->weather_que_city_comboBox->insertItem(35, "大理");
            ui->weather_que_city_comboBox->insertItem(36, "大连");
            ui->weather_que_city_comboBox->insertItem(37, "大庆");
            ui->weather_que_city_comboBox->insertItem(38, "大同");
            ui->weather_que_city_comboBox->insertItem(39, "丹东");
            ui->weather_que_city_comboBox->insertItem(40, "稻城");
            ui->weather_que_city_comboBox->insertItem(41, "东营");
            ui->weather_que_city_comboBox->insertItem(42, "敦煌");
            ui->weather_que_city_comboBox->insertItem(43, "芒市");
            ui->weather_que_city_comboBox->insertItem(44, "额济纳旗");
            ui->weather_que_city_comboBox->insertItem(45, "鄂尔多斯");
            ui->weather_que_city_comboBox->insertItem(46, "恩施");
            ui->weather_que_city_comboBox->insertItem(47, "二连浩特");
        }
        else if(arg1 == "FGHIJ")
        {
            ui->weather_que_city_comboBox->insertItem(0,  "佛山");
            ui->weather_que_city_comboBox->insertItem(1,  "福州");
            ui->weather_que_city_comboBox->insertItem(2,  "抚远");
            ui->weather_que_city_comboBox->insertItem(3,  "阜阳");
            ui->weather_que_city_comboBox->insertItem(4,  "赣州");
            ui->weather_que_city_comboBox->insertItem(5,  "格尔木");
            ui->weather_que_city_comboBox->insertItem(6,  "固原");
            ui->weather_que_city_comboBox->insertItem(7,  "广元");
            ui->weather_que_city_comboBox->insertItem(8,  "广州");
            ui->weather_que_city_comboBox->insertItem(9,  "贵阳");
            ui->weather_que_city_comboBox->insertItem(10, "桂林");
            ui->weather_que_city_comboBox->insertItem(11, "哈尔滨");
            ui->weather_que_city_comboBox->insertItem(12, "哈密");
            ui->weather_que_city_comboBox->insertItem(13, "海口");
            ui->weather_que_city_comboBox->insertItem(14, "海拉尔");
            ui->weather_que_city_comboBox->insertItem(15, "邯郸");
            ui->weather_que_city_comboBox->insertItem(16, "汉中");
            ui->weather_que_city_comboBox->insertItem(17, "杭州");
            ui->weather_que_city_comboBox->insertItem(18, "合肥");
            ui->weather_que_city_comboBox->insertItem(19, "和田");
            ui->weather_que_city_comboBox->insertItem(20, "黑河");
            ui->weather_que_city_comboBox->insertItem(21, "呼和浩特");
            ui->weather_que_city_comboBox->insertItem(22, "淮安");
            ui->weather_que_city_comboBox->insertItem(23, "怀化");
            ui->weather_que_city_comboBox->insertItem(24, "黄山");
            ui->weather_que_city_comboBox->insertItem(25, "惠州");
            ui->weather_que_city_comboBox->insertItem(26, "鸡西");
            ui->weather_que_city_comboBox->insertItem(27, "济南");
            ui->weather_que_city_comboBox->insertItem(28, "济宁");
            ui->weather_que_city_comboBox->insertItem(29, "加格达奇");
            ui->weather_que_city_comboBox->insertItem(30, "佳木斯");
            ui->weather_que_city_comboBox->insertItem(31, "嘉峪关");
            ui->weather_que_city_comboBox->insertItem(32, "金昌");
            ui->weather_que_city_comboBox->insertItem(33, "金门");
            ui->weather_que_city_comboBox->insertItem(34, "锦州");
            ui->weather_que_city_comboBox->insertItem(35, "嘉义");
            ui->weather_que_city_comboBox->insertItem(36, "西双版纳");
            ui->weather_que_city_comboBox->insertItem(37, "建三江");
            ui->weather_que_city_comboBox->insertItem(38, "晋江");
            ui->weather_que_city_comboBox->insertItem(39, "井冈山");
            ui->weather_que_city_comboBox->insertItem(40, "景德镇");
            ui->weather_que_city_comboBox->insertItem(41, "九江");
            ui->weather_que_city_comboBox->insertItem(42, "九寨沟");
        }
        else if(arg1 == "KLMNP")
        {
            ui->weather_que_city_comboBox->insertItem(0,  "喀什");
            ui->weather_que_city_comboBox->insertItem(1,  "凯里");
            ui->weather_que_city_comboBox->insertItem(2,  "康定");
            ui->weather_que_city_comboBox->insertItem(3,  "克拉玛依");
            ui->weather_que_city_comboBox->insertItem(4,  "库车");
            ui->weather_que_city_comboBox->insertItem(5,  "库尔勒");
            ui->weather_que_city_comboBox->insertItem(6,  "昆明");
            ui->weather_que_city_comboBox->insertItem(7,  "拉萨");
            ui->weather_que_city_comboBox->insertItem(8,  "兰州");
            ui->weather_que_city_comboBox->insertItem(9,  "黎平");
            ui->weather_que_city_comboBox->insertItem(10, "丽江");
            ui->weather_que_city_comboBox->insertItem(11, "荔波");
            ui->weather_que_city_comboBox->insertItem(12, "连云港");
            ui->weather_que_city_comboBox->insertItem(13, "六盘水");
            ui->weather_que_city_comboBox->insertItem(14, "临汾");
            ui->weather_que_city_comboBox->insertItem(15, "林芝");
            ui->weather_que_city_comboBox->insertItem(16, "临沧");
            ui->weather_que_city_comboBox->insertItem(17, "临沂");
            ui->weather_que_city_comboBox->insertItem(18, "柳州");
            ui->weather_que_city_comboBox->insertItem(19, "泸州");
            ui->weather_que_city_comboBox->insertItem(20, "洛阳");
            ui->weather_que_city_comboBox->insertItem(21, "吕梁");
            ui->weather_que_city_comboBox->insertItem(22, "澜沧");
            ui->weather_que_city_comboBox->insertItem(23, "龙岩");
            ui->weather_que_city_comboBox->insertItem(24, "满洲里");
            ui->weather_que_city_comboBox->insertItem(25, "梅州");
            ui->weather_que_city_comboBox->insertItem(26, "绵阳");
            ui->weather_que_city_comboBox->insertItem(27, "漠河");
            ui->weather_que_city_comboBox->insertItem(28, "牡丹江");
            ui->weather_que_city_comboBox->insertItem(29, "马祖");
            ui->weather_que_city_comboBox->insertItem(30, "南昌");
            ui->weather_que_city_comboBox->insertItem(31, "南充");
            ui->weather_que_city_comboBox->insertItem(32, "南京");
            ui->weather_que_city_comboBox->insertItem(33, "南宁");
            ui->weather_que_city_comboBox->insertItem(34, "南通");
            ui->weather_que_city_comboBox->insertItem(35, "南阳");
            ui->weather_que_city_comboBox->insertItem(36, "宁波");
            ui->weather_que_city_comboBox->insertItem(37, "宁蒗");
            ui->weather_que_city_comboBox->insertItem(38, "攀枝花");
            ui->weather_que_city_comboBox->insertItem(39, "普洱");
        }
        else if(arg1 == "QRSTUVW")
        {
            ui->weather_que_city_comboBox->insertItem(0,  "齐齐哈尔");
            ui->weather_que_city_comboBox->insertItem(1,  "黔江");
            ui->weather_que_city_comboBox->insertItem(2,  "且末");
            ui->weather_que_city_comboBox->insertItem(3,  "秦皇岛");
            ui->weather_que_city_comboBox->insertItem(4,  "青岛");
            ui->weather_que_city_comboBox->insertItem(5,  "庆阳");
            ui->weather_que_city_comboBox->insertItem(6,  "衢州");
            ui->weather_que_city_comboBox->insertItem(7,  "日喀则");
            ui->weather_que_city_comboBox->insertItem(8,  "日照");
            ui->weather_que_city_comboBox->insertItem(9,  "三亚");
            ui->weather_que_city_comboBox->insertItem(10, "厦门");
            ui->weather_que_city_comboBox->insertItem(11, "上海");
            ui->weather_que_city_comboBox->insertItem(12, "深圳");
            ui->weather_que_city_comboBox->insertItem(13, "神农架");
            ui->weather_que_city_comboBox->insertItem(14, "沈阳");
            ui->weather_que_city_comboBox->insertItem(15, "石家庄");
            ui->weather_que_city_comboBox->insertItem(16, "塔城");
            ui->weather_que_city_comboBox->insertItem(17, "台州");
            ui->weather_que_city_comboBox->insertItem(18, "太原");
            ui->weather_que_city_comboBox->insertItem(19, "扬州");
            ui->weather_que_city_comboBox->insertItem(20, "唐山");
            ui->weather_que_city_comboBox->insertItem(21, "腾冲");
            ui->weather_que_city_comboBox->insertItem(22, "天津");
            ui->weather_que_city_comboBox->insertItem(23, "天水");
            ui->weather_que_city_comboBox->insertItem(24, "通辽");
            ui->weather_que_city_comboBox->insertItem(25, "铜仁");
            ui->weather_que_city_comboBox->insertItem(26, "吐鲁番");
            ui->weather_que_city_comboBox->insertItem(27, "万州");
            ui->weather_que_city_comboBox->insertItem(28, "威海");
            ui->weather_que_city_comboBox->insertItem(29, "潍坊");
            ui->weather_que_city_comboBox->insertItem(30, "温州");
            ui->weather_que_city_comboBox->insertItem(31, "文山");
            ui->weather_que_city_comboBox->insertItem(32, "乌海");
            ui->weather_que_city_comboBox->insertItem(33, "乌兰浩特");
            ui->weather_que_city_comboBox->insertItem(34, "乌鲁木齐");
            ui->weather_que_city_comboBox->insertItem(35, "无锡");
            ui->weather_que_city_comboBox->insertItem(36, "梧州");
            ui->weather_que_city_comboBox->insertItem(37, "武汉");
            ui->weather_que_city_comboBox->insertItem(38, "武夷山");
        }
        else if(arg1 == "XYZ")
        {
            ui->weather_que_city_comboBox->insertItem(0,  "西安");
            ui->weather_que_city_comboBox->insertItem(1,  "西昌");
            ui->weather_que_city_comboBox->insertItem(2,  "西宁");
            ui->weather_que_city_comboBox->insertItem(3,  "锡林浩特");
            ui->weather_que_city_comboBox->insertItem(4,  "香格里拉");
            ui->weather_que_city_comboBox->insertItem(5,  "襄阳");
            ui->weather_que_city_comboBox->insertItem(6,  "兴义");
            ui->weather_que_city_comboBox->insertItem(7,  "徐州");
            ui->weather_que_city_comboBox->insertItem(8,  "香港");
            ui->weather_que_city_comboBox->insertItem(9,  "烟台");
            ui->weather_que_city_comboBox->insertItem(10, "延安");
            ui->weather_que_city_comboBox->insertItem(11, "延吉");
            ui->weather_que_city_comboBox->insertItem(12, "盐城");
            ui->weather_que_city_comboBox->insertItem(13, "伊春");
            ui->weather_que_city_comboBox->insertItem(14, "伊宁");
            ui->weather_que_city_comboBox->insertItem(15, "宜宾");
            ui->weather_que_city_comboBox->insertItem(16, "宜昌");
            ui->weather_que_city_comboBox->insertItem(17, "宜春");
            ui->weather_que_city_comboBox->insertItem(18, "义乌");
            ui->weather_que_city_comboBox->insertItem(19, "银川");
            ui->weather_que_city_comboBox->insertItem(20, "永州");
            ui->weather_que_city_comboBox->insertItem(21, "榆林");
            ui->weather_que_city_comboBox->insertItem(22, "玉树");
            ui->weather_que_city_comboBox->insertItem(23, "运城");
            ui->weather_que_city_comboBox->insertItem(24, "湛江");
            ui->weather_que_city_comboBox->insertItem(25, "张家界");
            ui->weather_que_city_comboBox->insertItem(26, "张家口");
            ui->weather_que_city_comboBox->insertItem(27, "张掖");
            ui->weather_que_city_comboBox->insertItem(28, "昭通");
            ui->weather_que_city_comboBox->insertItem(29, "郑州");
            ui->weather_que_city_comboBox->insertItem(30, "中卫");
            ui->weather_que_city_comboBox->insertItem(31, "舟山");
            ui->weather_que_city_comboBox->insertItem(32, "珠海");
            ui->weather_que_city_comboBox->insertItem(33, "遵义");
        }
}
