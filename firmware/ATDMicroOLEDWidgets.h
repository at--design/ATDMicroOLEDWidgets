#ifndef ATDMicroViewWidget_h
#define ATDMicroViewWidget_h

#include <stdio.h>
#include "application.h"
#include "SparkFunMicroOLED/SparkFunMicroOLED.h"

#define WIDGETNOVALUE			0x80

// Added for Vertical slider styles
#define WIDGETSTYLE2			2
#define WIDGETSTYLE3			3
#define PI 3.14159

class MicroViewWidget {
public:
    MicroViewWidget(uint8_t newx, uint8_t newy, int16_t min, int16_t max);
    uint8_t getX();
    uint8_t getY();
    void setX(uint8_t newx);
    void setY(uint8_t newy);
    int16_t getMinValue();
    int16_t getMaxValue();
    int16_t getValue();
    void setMinValue(int16_t min);
    void setMaxValue(int16_t max);
    void setValue(int16_t val);
    uint8_t getValLen();
    uint8_t getMaxValLen();
    /** \brief Draw widget value overridden by child class. */
    virtual void draw(){};
    /** \brief Draw widget face overridden by child class. */
    virtual void drawFace(){};
    void reDraw();
    void drawNumValue(int16_t value);
    virtual ~MicroViewWidget(){};
protected:
    uint8_t posX;
    uint8_t posY;
    int16_t minValue;
    int16_t maxValue;
    int16_t value;
    uint8_t valLen;
    uint8_t maxValLen;
private:
    /** \brief Draw or erase the widget pointer. Overridden by child class. */
    virtual void drawPointer(){};
    void setMaxValLen();
};

class MicroViewSlider: public MicroViewWidget{
public:
    MicroViewSlider(uint8_t newx, uint8_t newy, int16_t min, int16_t max);
    MicroViewSlider(uint8_t newx, uint8_t newy, int16_t min, int16_t max, uint8_t sty);
    void draw();
    void drawFace();
private:
    void drawPointer();
    uint8_t style, totalTicks;
    bool noValDraw;
    int16_t prevValue;
};

class MicroViewGauge: public MicroViewWidget{
public:
    MicroViewGauge(uint8_t newx, uint8_t newy, int16_t min, int16_t max);
    MicroViewGauge(uint8_t newx, uint8_t newy, int16_t min, int16_t max, uint8_t sty);
    void draw();
    void drawFace();
private:
    void drawPointer();
    uint8_t style, radius;
    bool noValDraw;
    int16_t prevValue;
};

uint8_t getInt16PrintLen(int16_t val);
extern MicroOLED uView;
#endif