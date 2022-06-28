#include <iostream>

#include "list_devices.hpp"

int main() {

    std::vector<v4l2::devices::DEVICE_INFO> devices;

    v4l2::devices::list(devices);

    for (const auto & device : devices) 
    {
        //std::cout << device.device_description <<  " at " << device.bus_info << " is attached to\n";

        for (const auto & path : device.device_paths)
        {
            auto res = device.device_description.find("ar0233");

            if(device.device_description.find("ar0233") < 64)
            {
                std::cout << path.c_str() << " is NileCAM21\n";
                if ( -1 == symlink( path.c_str(), "/home/nvidia/gmsl"))
                {
                    std::cout << path << " link created as \n";
                }
            }
            else if(device.device_description.find("See3CAM_CU20") < 64)
            {
                std::cout << path.c_str() << " is See3CAM_CU20\n";
                if ( -1 == symlink( path.c_str(), "/home/nvidia/usb"))
                {
                    std::cout << path << " link created as\n";
                }
            }
        }

        std::cout << "\n";
    }

}