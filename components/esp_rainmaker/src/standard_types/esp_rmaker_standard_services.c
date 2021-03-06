// Copyright 2020 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <esp_rmaker_standard_types.h>
#include <esp_rmaker_standard_params.h>

esp_rmaker_device_t *esp_rmaker_ota_service_create(const char *serv_name, void *priv_data)
{
    esp_rmaker_device_t *service = esp_rmaker_service_create(serv_name, ESP_RMAKER_SERVICE_OTA, priv_data);
    if (service) {
        esp_rmaker_device_add_param(service, esp_rmaker_ota_status_param_create(ESP_RMAKER_DEF_OTA_STATUS_NAME));
        esp_rmaker_device_add_param(service, esp_rmaker_ota_info_param_create(ESP_RMAKER_DEF_OTA_INFO_NAME));
        esp_rmaker_device_add_param(service, esp_rmaker_ota_url_param_create(ESP_RMAKER_DEF_OTA_URL_NAME));
    }
    return service;
}

