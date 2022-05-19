#include <claragenomics/utils/cudautils.hpp>

static std::unique_ptr<char, void (*)(char *)> create_buffer(size_t buffer_size)
{
    // shared_ptr creation packed in a function so it can be used in constructor's initilaization list
    void *ptr = nullptr;
    CGA_CU_CHECK_ERR(cudaMalloc(&ptr, buffer_size));
    auto ret_val = std::unique_ptr<char, void (*)(char *)>(static_cast<char *>(ptr),
                                                           [](char *ptr)
                                                           {
                                                               CGA_CU_ABORT_ON_ERR(cudaFree(ptr));
                                                           });
    return ret_val;
}