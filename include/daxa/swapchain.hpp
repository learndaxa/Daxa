#pragma once

#include <daxa/core.hpp>

#include <daxa/gpu_resources.hpp>

namespace daxa
{
    struct SwapchainInfo
    {
        NativeWindowHandle native_window_handle;
        u32 width = 0;
        u32 height = 0;
        PresentMode present_mode = PresentMode::DOUBLE_BUFFER_WAIT_FOR_VBLANK;
        PresentOp present_operation = PresentOp::IDENTITY;
        ImageUsageFlags image_usage = {};
        std::string debug_name = {};
    };

    struct Swapchain : Handle
    {
        auto info() const -> SwapchainInfo const &;

        ImageId acquire_next_image();
        void resize(u32 width, u32 height);
        void change_present_mode(PresentMode new_present_mode);

      private:
        friend struct Device;
        Swapchain(std::shared_ptr<void> impl);
    };
} // namespace daxa
