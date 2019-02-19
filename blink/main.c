#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpio.h"
#include "bsp.h"


int main(void)
{


    gpio_pin_value_t arr[3][3] = {{GPIO_PV_LOW, GPIO_PV_HIGH, GPIO_PV_HIGH},{GPIO_PV_HIGH, GPIO_PV_LOW, GPIO_PV_HIGH},{GPIO_PV_HIGH, GPIO_PV_HIGH, GPIO_PV_LOW}};

    
    fpioa_set_function(12, FUNC_GPIO3);
    fpioa_set_function(13, FUNC_GPIO4);
    fpioa_set_function(14, FUNC_GPIO5);

    gpio_init();

    gpio_set_drive_mode(3, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(4, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(5, GPIO_DM_OUTPUT);
	

    gpio_pin_value_t value_b = GPIO_PV_HIGH;
    gpio_pin_value_t value_g = GPIO_PV_HIGH;
    gpio_pin_value_t value_r = GPIO_PV_HIGH;



    gpio_set_pin(3, value_b);
    gpio_set_pin(4, value_g);
    gpio_set_pin(5, value_r);

	while(1) {    
        for(uint8_t i = 0; i<3; i++) {
        	sleep(1);
        	gpio_set_pin(5, arr[i][0]);
        	gpio_set_pin(4, arr[i][1]);
        	gpio_set_pin(3, arr[i][2]);
    	}
	}

    return 0;
}
