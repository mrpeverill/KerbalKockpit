/* Definitions */
#define TRUE 1
#define FALSE 0
//#define DEBUG               /* This flag will enable debug code */

/* Analog Multiplex Vars */
const int selectPins[3] = {2, 3, 4}; // S0~2, S1~3, S2~4
const int zOutput = 5; 
const int zInput = A0; // Connect common (Z) to A0 (analog input)

/* Variables */
byte x_databuffer[40];                  /* byte buffer for managing outputs */
byte x_inputbuffer[3];                  /* byte bugger for managing inputs */
//char s_ap_text1[41];                    /* AP panel message text line 1*/
//char s_ap_text2[41];                    /* AP panel message text line 2*/
//char s_ap_text_cons[3][13];             /* AP text constructor strings */
int f_data_received = 0;                /* data received flag */
int f_data_requested = 0;               /* data requested flag */
int i;                                  /* general loop counter */
int j;                                  /* general loop counter */
int n_mux_chips_detected = 0;           /* number of MUX chips detected in the IBIT */
//int n_ap_subband_count = 0;             /* Counter for AP subbanding */
//int n_ap_faststep_ucount[3] = {0,0,0};  /* Counter for AP button hold delay */
//int n_ap_faststep_dcount[3] = {0,0,0};  /* Counter for AP button hold delay */
int f_critical_error = 0;               /* critical error detected flag */
int f_power_on_first_pass = 1;          /* first pass flag when main power is turned on */
//int x_fan_speed = 0;                    /* fan speed setting */
int x_dimmer_setting = 0;               /* dimmer setting */
int f_power_light_state = 0;            /* power light flash state */
int f_error_light_state = 0;            /* error light flash state */
int f_serial_state = 0;                 /* state of serial comm */
//int f_ap_power_state = 0;               /* AP power state */
//int f_ap_system_state = 0;              /* AP System Mode State off, init, running */
//int f_ap_screen_refresh = 0;            /* AP panel screen refresh flag */
//int f_ap_pwr_p;                         /* AP power button previous state */
//int f_ap_cancel_p;                      /* AP cancel button previous state */
//int f_ap_inputs[3][6];                  /* AP panel button inputs mapped from raw inputs */
//int f_ap_inputs_p[3][6];                /* AP panel button input previous values for debounce */
unsigned long t_power_light = 0;        /* timer for power light flashing calculation */
unsigned long t_overun_light = 0;       /* timer for overun light hold calculation */
unsigned long t_current_frame = 0;      /* current frame start time */
unsigned long t_frame_time = 0;         /* the simulation time for the current frame */
unsigned long t_last_frame = 0;         /* time since last frame */
unsigned long t_frame_actual = 0;       /* actual time it took to process the current frame */
unsigned long t_run_time = 0;           /* time since main power on */
unsigned long t_power_on = 0;           /* time when main power came on */
//unsigned long t_gear_flash_timer = 0;   /* timer for gear light flash calculation */
unsigned long t_last_serial_time = 0;   /* time since last serial data arrived */
unsigned long t_error_light = 100;        /* timer for error light flashing */
//unsigned long t_ap_init_timer = 0;      /* AP init mode timer */

/* constants */
//const int c_voltage_threshold = 600;    /* voltage sensor limit for externally powered [-]*/
const int c_power_light_flash = 1000;   /* power light flash rate [ms] */
const int c_num_mux_chips = 1;          /* the number of MCP23017 chips installed [-]*/
const int c_error_code_mux_missing = 1; /* error code if MUX count is incorrect [-]*/
const int c_frame_time_target = 25;     /* target frame time [ms]*/
//const int c_fan_power_up_time = 5000;   /* Time that fan will run full speed at start [ms]*/
const int c_temp_max = 160;             /* overtemp limit, stop. Equates to about 3 degrees above max fan speed.  [-]*/
const int c_overtemp_error_code = 2;    /* error code if overtemp limit exceeded [-]*/
//const int c_gear_light_flash = 100;     /* gear light flash rate [ms]*/
const int c_first_mux_address = 0x20;     /* the first I2C address in the MUX range [-]*/
const int c_last_mux_address = 0x21;      /* the last I2C address in the MUX range [-]*/
const int c_light_bit_time = 1000;      /* time to delay to allow light BIT test to be seen [ms]*/
const int c_serial_timeout = 5000;      /* serial timeout [ms]*/
const int c_error_light_flash = 250;    /* no data flash rate for error light [ms]*/
//const int c_ap_init_time = 3000;        /* Init time for the AP display [ms]*/
//const int c_ap_subband = 10;            /* Subbanding of AP panel, AP code runs every nth frame [-]*/
//const int c_ap_faststep_delay = 5;      /* Number of AP frames with button held to use fast more [-]*/
//const float c_fan_speed_m = 3.448;      /* fan speed vs temp slope [rpm/deg]*/
//const float c_fan_speed_b = -282.931;   /* fan speed vs temp Y intercept [rpm]*/
const long c_serial_speed = 115200;     /* serial bus baud rate [baud]*/

/* pin mappings */
//const int c_dimmer_pwm_pin = 2;
//const int c_ap_power_pin = 3;
//const int c_ap_reset_pin = 4;
//const int c_ap_dimmer_pin = 5;
//const int c_fan_pwm_pin = 6;
const int c_overrun_led_pin = 7;
const int c_error_led_pin = 8;
const int c_power_led_pin = 5;

/* pin ranges */
const int c_first_input_pin1 = 9;       /* the first pin used for digital IO */
const int c_last_input_pin1 = 10;        /* the last input pin used for digital IO */
//const int c_first_input_pin2 = 22;      /* the first pin used for digital IO */
//const int c_last_input_pin2 = 54;       /* the last input pin used for digital IO */
//const int c_first_pwm_pin = 2;          /* the first pin used for digital output */
//const int c_last_pwm_pin = 6;           /* the last output pin used for digital IO */
const int c_first_output_pin = 2;      /* the first pin used for digital output */
const int c_last_output_pin = 5;       /* the last output pin used for digital IO */

/* function prototypes*/
int read_inputs(byte buff[]);
int write_outputs(byte inputs[], byte outputs[]);
//int autopilot(byte databuffer[]);
