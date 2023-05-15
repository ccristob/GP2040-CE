#include "config_legacy.h"
#include "config_utils.h"

#include "config.pb.h"

const size_t GAMEPAD_STORAGE_INDEX      =    0; // 1024 bytes for gamepad options
const size_t BOARD_STORAGE_INDEX        = 1024; //  512 bytes for hardware options
const size_t LED_STORAGE_INDEX          = 1536; //  512 bytes for LED configuration
const size_t ANIMATION_STORAGE_INDEX    = 2048; // 1024 bytes for LED animations
const size_t ADDON_STORAGE_INDEX        = 3072; // 1024 bytes for Add-Ons
const size_t PS4_STORAGE_INDEX          = 4096; // 2048 bytes for PS4 options
const size_t SPLASH_IMAGE_STORAGE_INDEX = 6144; // 1032 bytes for Display Config

const uint32_t CHECKSUM_MAGIC   = 0;
const uint32_t NOCHECKSUM_MAGIC = 0xDEADBEEF;   // No checksum CRC;

namespace ConfigLegacy
{
    struct PS4Options {
        uint8_t serial[16];
        uint8_t signature[256];
        mbedtls_mpi_uint rsa_n[64];
        mbedtls_mpi_uint rsa_e[1];
        mbedtls_mpi_uint rsa_d[64];
        mbedtls_mpi_uint rsa_p[32];
        mbedtls_mpi_uint rsa_q[32];
        mbedtls_mpi_uint rsa_dp[32];
        mbedtls_mpi_uint rsa_dq[32];
        mbedtls_mpi_uint rsa_qp[32];
        mbedtls_mpi_uint rsa_rn[64];
        uint32_t checksum;
    };

    struct SplashImage {
        uint8_t data[16*64];
        uint32_t checksum;
    };
}

bool ConfigUtils::fromLegacyStorage(Config& config)
{
    return false;
}
