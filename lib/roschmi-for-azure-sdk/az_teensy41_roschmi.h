#ifndef _AZ_TEENSY41_ROSCHMI_H_
#define _AZ_TEENSY41_ROSCHMI_H_


#include <Arduino.h>
#include <stdlib.h>
#include <string.h>
#include "azure/core/az_span.h"
#include "azure/core/az_http_transport.h"
#include "azure/core/az_platform.h"
#include "azure/core/az_http.h"
#include <azure/core/az_result.h>
#include <azure/core/internal/az_result_internal.h>
#include <azure/core/az_span.h>
#include <azure/core/internal/az_span_internal.h>

#include "EthernetHttpClient_SSL.h"

#include "EthernetWebServer_SSL.h"

#include "Watchdog_t4.h"

#define MAX_HEADERNAME_LENGTH 30
#define MAX_HEADERVALUE_LENGTH 120

// RoSchmi
//static az_result dev_az_http_client_build_headers(
az_result dev_az_http_client_build_headers(
az_http_request const* request, 
az_span headers_span); 
    
// RoSchmi
static az_result dev_az_span_append_header_to_buffer(
//az_result dev_az_span_append_header_to_buffer( 
az_span writable_buffer,
az_span header_name,
az_span header_value,
az_span separator);

#include "az_teensy41_roschmi_Impl.h"
    
#endif