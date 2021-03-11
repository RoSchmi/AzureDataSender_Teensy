#include <Arduino.h>
#include "EthernetWebServer_SSL.h"

#include "Timezone_Generic.h"

//#include "time.h"

#include "mbedtls/md.h"
#include "mbedtls/md5.h"
#include "mbedtls/base64.h"
#include "mbedtls/sha256.h"
#include "azure/core/az_http.h"

#include "SysTime.h"
#include "Rs_time_helpers.h"
#include "CloudStorageAccount.h"
#include "TableEntity.h"
#include "RoSchmi_encryption_helpers.h"

#include "roschmi_az_storage_tables.h"
#include "az_wioterminal_roschmi.h"

#ifndef _TABLECLIENT_H_
#define _TABLECLIENT_H_

#define MAX_TABLENAME_LENGTH 50
#define RESPONSE_BUFFER_MEMORY_ADDR 0x2002A000
//#define RESPONSE_BUFFER_MEMORY_ADDR   0x20030000
#define RESPONSE_BUFFER_LENGTH 2000
#define REQUEST_BODY_BUFFER_MEMORY_ADDR 0x20029200
#define REQUEST_BODY_BUFFER_LENGTH 900
#define PROPERTIES_BUFFER_MEMORY_ADDR 0x20029000
#define PROPERTIES_BUFFER_LENGTH 300


   typedef enum {
      useHttp,
      useHttps
  } Protocol;

  typedef enum {
    contApplicationIatomIxml,
    contApplicationIjson
    } ContType;

typedef enum 
        {
            acceptApplicationIatomIxml,
            acceptApplicationIjson
        } AcceptType;

typedef enum 
        {
            returnContent,
            dont_returnContent
        } ResponseType;

struct mytm
{
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
};


class TableClient
{
public:

TableClient(CloudStorageAccount *account, Protocol protocol, br_x509_trust_anchor tAs, size_t numTA, EthernetClient * ethernet_client, EthernetSSLClient * ethernetSslClient, EthernetHttpClient * ethernetHttpClient);

/*
#if (USE_ENC28_ETHERNET == 1)
    
    #endif

#if USE_ENC28_ETHERNET == 1

    
#endif
*/
    ~TableClient();
    
    az_http_status_code CreateTable(const char * tableName, ContType pContentType = ContType::contApplicationIatomIxml, AcceptType pAcceptType = AcceptType::acceptApplicationIjson, ResponseType pResponseType = ResponseType::returnContent, bool useSharedKeyLight = false);
    az_http_status_code InsertTableEntity(const char * tableName, TableEntity pEntity, char* out_ETAG, DateTime * outResonseHeaderDate, ContType pContentType, AcceptType pAcceptType, ResponseType pResponseType, bool useSharedKeyLite = false);   
    void CreateTableAuthorizationHeader(const char * content, const char * canonicalResource, const char * ptimeStamp, const char * pHttpVerb, az_span pConentType, char * pMd5Hash, char pAutorizationHeader[], bool useSharedKeyLite = false);
    int32_t dow(int32_t year, int32_t month, int32_t day);

private:

SysTime sysTime;
//EthernetSSLClient * _ethernetClient = NULL;
//WiFiClient* _wiFiClient = nullptr;
//EthernetClient& _ethernetClient;
};

#include "TableClient_Impl.h"
#endif 