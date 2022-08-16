#if DAXA_BUILT_WITH_UTILS

#include "impl_task_list.hpp"
#include <iostream>

#include <fstream>

namespace daxa
{
    auto TaskGPUResourceId::is_empty() const -> bool
    {
        return index == std::numeric_limits<u32>::max();
    }

    auto to_string(TaskBufferAccess const & usage) -> std::string_view
    {
        switch (usage)
        {
        case TaskBufferAccess::SHADER_READ_ONLY: return std::string_view{"SHADER_READ_ONLY"};
        case TaskBufferAccess::VERTEX_SHADER_READ_ONLY: return std::string_view{"VERTEX_SHADER_READ_ONLY"};
        case TaskBufferAccess::TESSELLATION_CONTROL_SHADER_READ_ONLY: return std::string_view{"TESSELLATION_CONTROL_SHADER_READ_ONLY"};
        case TaskBufferAccess::TESSELLATION_EVALUATION_SHADER_READ_ONLY: return std::string_view{"TESSELLATION_EVALUATION_SHADER_READ_ONLY"};
        case TaskBufferAccess::GEOMETRY_SHADER_READ_ONLY: return std::string_view{"GEOMETRY_SHADER_READ_ONLY"};
        case TaskBufferAccess::FRAGMENT_SHADER_READ_ONLY: return std::string_view{"FRAGMENT_SHADER_READ_ONLY"};
        case TaskBufferAccess::COMPUTE_SHADER_READ_ONLY: return std::string_view{"COMPUTE_SHADER_READ_ONLY"};
        case TaskBufferAccess::SHADER_WRITE_ONLY: return std::string_view{"SHADER_WRITE_ONLY"};
        case TaskBufferAccess::VERTEX_SHADER_WRITE_ONLY: return std::string_view{"VERTEX_SHADER_WRITE_ONLY"};
        case TaskBufferAccess::TESSELLATION_CONTROL_SHADER_WRITE_ONLY: return std::string_view{"TESSELLATION_CONTROL_SHADER_WRITE_ONLY"};
        case TaskBufferAccess::TESSELLATION_EVALUATION_SHADER_WRITE_ONLY: return std::string_view{"TESSELLATION_EVALUATION_SHADER_WRITE_ONLY"};
        case TaskBufferAccess::GEOMETRY_SHADER_WRITE_ONLY: return std::string_view{"GEOMETRY_SHADER_WRITE_ONLY"};
        case TaskBufferAccess::FRAGMENT_SHADER_WRITE_ONLY: return std::string_view{"FRAGMENT_SHADER_WRITE_ONLY"};
        case TaskBufferAccess::COMPUTE_SHADER_WRITE_ONLY: return std::string_view{"COMPUTE_SHADER_WRITE_ONLY"};
        case TaskBufferAccess::SHADER_READ_WRITE: return std::string_view{"SHADER_READ_WRITE"};
        case TaskBufferAccess::VERTEX_SHADER_READ_WRITE: return std::string_view{"VERTEX_SHADER_READ_WRITE"};
        case TaskBufferAccess::TESSELLATION_CONTROL_SHADER_READ_WRITE: return std::string_view{"TESSELLATION_CONTROL_SHADER_READ_WRITE"};
        case TaskBufferAccess::TESSELLATION_EVALUATION_SHADER_READ_WRITE: return std::string_view{"TESSELLATION_EVALUATION_SHADER_READ_WRITE"};
        case TaskBufferAccess::GEOMETRY_SHADER_READ_WRITE: return std::string_view{"GEOMETRY_SHADER_READ_WRITE"};
        case TaskBufferAccess::FRAGMENT_SHADER_READ_WRITE: return std::string_view{"FRAGMENT_SHADER_READ_WRITE"};
        case TaskBufferAccess::COMPUTE_SHADER_READ_WRITE: return std::string_view{"COMPUTE_SHADER_READ_WRITE"};
        case TaskBufferAccess::TRANSFER_READ: return std::string_view{"TRANSFER_READ"};
        case TaskBufferAccess::TRANSFER_WRITE: return std::string_view{"TRANSFER_WRITE"};
        case TaskBufferAccess::HOST_TRANSFER_READ: return std::string_view{"HOST_TRANSFER_READ"};
        case TaskBufferAccess::HOST_TRANSFER_WRITE: return std::string_view{"HOST_TRANSFER_WRITE"};
        default: DAXA_DBG_ASSERT_TRUE_M(false, "unreachable");
        }
        return "invalid";
    }

    auto to_string(TaskImageAccess const & usage) -> std::string_view
    {
        switch (usage)
        {
        case TaskImageAccess::SHADER_READ_ONLY: return std::string_view{"SHADER_READ_ONLY"};
        case TaskImageAccess::VERTEX_SHADER_READ_ONLY: return std::string_view{"VERTEX_SHADER_READ_ONLY"};
        case TaskImageAccess::TESSELLATION_CONTROL_SHADER_READ_ONLY: return std::string_view{"TESSELLATION_CONTROL_SHADER_READ_ONLY"};
        case TaskImageAccess::TESSELLATION_EVALUATION_SHADER_READ_ONLY: return std::string_view{"TESSELLATION_EVALUATION_SHADER_READ_ONLY"};
        case TaskImageAccess::GEOMETRY_SHADER_READ_ONLY: return std::string_view{"GEOMETRY_SHADER_READ_ONLY"};
        case TaskImageAccess::FRAGMENT_SHADER_READ_ONLY: return std::string_view{"FRAGMENT_SHADER_READ_ONLY"};
        case TaskImageAccess::COMPUTE_SHADER_READ_ONLY: return std::string_view{"COMPUTE_SHADER_READ_ONLY"};
        case TaskImageAccess::SHADER_WRITE_ONLY: return std::string_view{"SHADER_WRITE_ONLY"};
        case TaskImageAccess::VERTEX_SHADER_WRITE_ONLY: return std::string_view{"VERTEX_SHADER_WRITE_ONLY"};
        case TaskImageAccess::TESSELLATION_CONTROL_SHADER_WRITE_ONLY: return std::string_view{"TESSELLATION_CONTROL_SHADER_WRITE_ONLY"};
        case TaskImageAccess::TESSELLATION_EVALUATION_SHADER_WRITE_ONLY: return std::string_view{"TESSELLATION_EVALUATION_SHADER_WRITE_ONLY"};
        case TaskImageAccess::GEOMETRY_SHADER_WRITE_ONLY: return std::string_view{"GEOMETRY_SHADER_WRITE_ONLY"};
        case TaskImageAccess::FRAGMENT_SHADER_WRITE_ONLY: return std::string_view{"FRAGMENT_SHADER_WRITE_ONLY"};
        case TaskImageAccess::COMPUTE_SHADER_WRITE_ONLY: return std::string_view{"COMPUTE_SHADER_WRITE_ONLY"};
        case TaskImageAccess::SHADER_READ_WRITE: return std::string_view{"SHADER_READ_WRITE"};
        case TaskImageAccess::VERTEX_SHADER_READ_WRITE: return std::string_view{"VERTEX_SHADER_READ_WRITE"};
        case TaskImageAccess::TESSELLATION_CONTROL_SHADER_READ_WRITE: return std::string_view{"TESSELLATION_CONTROL_SHADER_READ_WRITE"};
        case TaskImageAccess::TESSELLATION_EVALUATION_SHADER_READ_WRITE: return std::string_view{"TESSELLATION_EVALUATION_SHADER_READ_WRITE"};
        case TaskImageAccess::GEOMETRY_SHADER_READ_WRITE: return std::string_view{"GEOMETRY_SHADER_READ_WRITE"};
        case TaskImageAccess::FRAGMENT_SHADER_READ_WRITE: return std::string_view{"FRAGMENT_SHADER_READ_WRITE"};
        case TaskImageAccess::COMPUTE_SHADER_READ_WRITE: return std::string_view{"COMPUTE_SHADER_READ_WRITE"};
        case TaskImageAccess::TRANSFER_READ: return std::string_view{"TRANSFER_READ"};
        case TaskImageAccess::TRANSFER_WRITE: return std::string_view{"TRANSFER_WRITE"};
        case TaskImageAccess::COLOR_ATTACHMENT: return std::string_view{"COLOR_ATTACHMENT"};
        case TaskImageAccess::DEPTH_ATTACHMENT: return std::string_view{"DEPTH_ATTACHMENT"};
        case TaskImageAccess::STENCIL_ATTACHMENT: return std::string_view{"STENCIL_ATTACHMENT"};
        case TaskImageAccess::DEPTH_STENCIL_ATTACHMENT: return std::string_view{"DEPTH_STENCIL_ATTACHMENT"};
        case TaskImageAccess::DEPTH_ATTACHMENT_READ_ONLY: return std::string_view{"DEPTH_ATTACHMENT_READ_ONLY"};
        case TaskImageAccess::STENCIL_ATTACHMENT_READ_ONLY: return std::string_view{"STENCIL_ATTACHMENT_READ_ONLY"};
        case TaskImageAccess::DEPTH_STENCIL_ATTACHMENT_READ_ONLY: return std::string_view{"DEPTH_STENCIL_ATTACHMENT_READ_ONLY"};
        case TaskImageAccess::RESOLVE_WRITE: return std::string_view{"RESOLVE_WRITE"};
        case TaskImageAccess::PRESENT: return std::string_view{"PRESENT"};
        default: DAXA_DBG_ASSERT_TRUE_M(false, "unreachable");
        }
        return "invalid";
    }

    TaskInterface::TaskInterface(void * backend, TaskResources * resources)
        : backend{backend}, resources{resources}
    {
    }

    auto TaskInterface::get_device() -> Device &
    {
        auto & impl = *reinterpret_cast<TaskRuntime *>(backend);
        return impl.current_device;
    }

    auto TaskInterface::get_command_list() -> CommandList
    {
        auto & impl = *reinterpret_cast<TaskRuntime *>(backend);
        if (impl.reuse_last_command_list)
        {
            impl.reuse_last_command_list = false;
            return impl.command_lists.back();
        }
        else
        {
            impl.command_lists.push_back({impl.current_device.create_command_list({.debug_name = std::string("Task Command List ") + std::to_string(impl.command_lists.size())})});
            return impl.command_lists.back();
        }
    }

    auto TaskInterface::get_resources() -> TaskResources &
    {
        return *resources;
    }

    auto TaskInterface::get_buffer(TaskBufferId const & task_id) -> BufferId
    {
        auto & impl = *reinterpret_cast<TaskRuntime *>(backend);
        return impl.runtime_buffers[task_id.index].buffer_id;
    }

    auto TaskInterface::get_image(TaskImageId const & task_id) -> ImageId
    {
        auto & impl = *reinterpret_cast<TaskRuntime *>(backend);
        return impl.runtime_images[task_id.index].image_id;
    }

    auto TaskInterface::get_image_view(TaskImageId const & task_id) -> ImageViewId
    {
        auto & impl = *reinterpret_cast<TaskRuntime *>(backend);
        return impl.runtime_images[task_id.index].image_view_id;
    }

    auto TaskInterface::get_image_slice(TaskImageId const & task_id) -> ImageMipArraySlice
    {
        auto & impl = *reinterpret_cast<TaskRuntime *>(backend);
        return impl.impl_task_images[task_id.index].slice;
    }

    TaskList::TaskList(TaskListInfo const & info)
        : ManagedPtr{new ImplTaskList(info)}
    {
    }

    TaskList::~TaskList() {}

    auto TaskList::create_task_buffer(TaskBufferInfo const & info) -> TaskBufferId
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(!impl.compiled, "can only record to uncompleted task list");

        usize task_index = impl.tasks.size() + 1;

        impl.impl_task_buffers.push_back(ImplTaskBuffer{
            .latest_access = info.last_access,
            .latest_access_task_index = task_index,
            .fetch_callback = info.fetch_callback,
            .debug_name = info.debug_name,
        });

        auto task_buffer_id = TaskBufferId{{.index = static_cast<u32>(impl.impl_task_buffers.size() - 1)}};

        impl.tasks.push_back(
            {
                .parent_scope_id = impl.record_state.get_current_scope_id(),
                .event_variant = ImplCreateBufferTask{
                    .id = task_buffer_id,
                },
            });

        return task_buffer_id;
    }

    auto TaskList::create_task_image(TaskImageInfo const & info) -> TaskImageId
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(!impl.compiled, "can only record to uncompleted task list");

        usize task_index = impl.tasks.size() + 1;

        impl.impl_task_images.push_back(ImplTaskImage{
            .latest_access = info.last_access,
            .latest_layout = info.last_layout,
            .latest_access_task_index = task_index,
            .fetch_callback = info.fetch_callback,
            .slice = info.slice,
            .debug_name = info.debug_name,
        });

        auto task_image_id = TaskImageId{{.index = static_cast<u32>(impl.impl_task_images.size() - 1)}};

        impl.tasks.push_back({
            .parent_scope_id = impl.record_state.get_current_scope_id(),
            .event_variant = ImplCreateImageTask{
                .id = task_image_id,
            },
        });

        return task_image_id;
    }

    void TaskList::add_task(TaskInfo const & info)
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(!impl.compiled, "can only record to uncompleted task list");
        impl.tasks.push_back({
            .parent_scope_id = impl.record_state.get_current_scope_id(),
            .event_variant = ImplGenericTask{
                .info = info,
            },
        });

        if (!impl.record_state.conditional_task_indices.empty())
        {
            usize conditional_scope_begin_index = impl.record_state.conditional_task_indices.top();
            usize task_index = impl.tasks.size();
            ImplConditionalTaskBegin * conditional_begin = std::get_if<ImplConditionalTaskBegin>(&impl.tasks[conditional_scope_begin_index].event_variant);
            DAXA_DBG_ASSERT_TRUE_M(conditional_begin != nullptr, "unreachable. possible cause: bad value in conditional_task_indices");

            // The task we just added could use a resource OUTSIDE of the conditional scope.
            // All resource access that goes beyond the conditional scope must be recorded by the scope.
            for (auto & imgtup : info.resources.images)
            {
                if (impl.impl_task_images[std::get<0>(imgtup).index].latest_access_task_index < conditional_scope_begin_index)
                {
                    conditional_begin->resources.images.push_back(imgtup);
                }
            }
            for (auto & buftup : info.resources.buffers)
            {
                if (impl.impl_task_buffers[std::get<0>(buftup).index].latest_access_task_index < conditional_scope_begin_index)
                {
                    conditional_begin->resources.buffers.push_back(buftup);
                }
            }
        }
    }

    void TaskList::add_copy_image_to_image(TaskCopyImageInfo const & info)
    {
        add_task({
            .resources = {
                .images = {
                    {info.src_image, daxa::TaskImageAccess::TRANSFER_READ},
                    {info.dst_image, daxa::TaskImageAccess::TRANSFER_WRITE},
                }},
            .task = [=](TaskInterface & interface)
            {
                auto cmd = interface.get_command_list();

                auto src_image = interface.get_image(info.src_image);
                auto dst_image = interface.get_image(info.dst_image);

                auto src_t_slice = interface.get_image_slice(info.src_image);
                auto dst_t_slice = interface.get_image_slice(info.dst_image);

                DAXA_DBG_ASSERT_TRUE_M(info.src_slice.contained_in(src_t_slice), "copy src slice must be contained in task src images slice");
                DAXA_DBG_ASSERT_TRUE_M(info.dst_slice.contained_in(dst_t_slice), "copy src slice must be contained in task dst images slice");

                cmd.copy_image_to_image({
                    .src_image = src_image,
                    .src_image_layout = daxa::ImageLayout::TRANSFER_SRC_OPTIMAL,
                    .dst_image = dst_image,
                    .dst_image_layout = daxa::ImageLayout::TRANSFER_DST_OPTIMAL,
                    .src_slice = info.src_slice,
                    .src_offset = info.src_offset,
                    .dst_slice = info.dst_slice,
                    .dst_offset = info.dst_offset,
                    .extent = info.extent,
                });
            },
            .debug_name = info.debug_name,
        });
    }

    void TaskList::add_clear_image(TaskImageClearInfo const & info)
    {
        add_task({
            .resources = {
                .images = {
                    {info.dst_image, daxa::TaskImageAccess::TRANSFER_WRITE},
                }},
            .task = [=](TaskInterface & interface)
            {
                auto cmd = interface.get_command_list();

                auto dst_image = interface.get_image(info.dst_image);

                auto dst_t_slice = interface.get_image_slice(info.dst_image);

                DAXA_DBG_ASSERT_TRUE_M(info.dst_slice.contained_in(dst_t_slice), "clear dst slice must be contained in task dst images slice");

                cmd.clear_image({
                    .dst_image_layout = ImageLayout::TRANSFER_DST_OPTIMAL,
                    .clear_value = info.clear_value,
                    .dst_image = dst_image,
                    .dst_slice = info.dst_slice,
                });
            },
            .debug_name = info.debug_name,
        });
    }

    void TaskList::compile()
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(!impl.compiled, "Can only compile a task list one time");

        impl.compiled = true;

        impl.insert_synchronization();
    }

    void TaskList::output_graphviz()
    {
        auto & impl = *as<ImplTaskList>();
        impl.output_graphviz();
    }

    void TaskList::execute()
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(impl.compiled, "Can only execute a completed task list");

        TaskRuntime runtime{
            .current_device = impl.info.device,
            .command_lists = {impl.info.device.create_command_list({.debug_name = {std::string("Task Command List 0")}})},
            .impl_task_buffers = impl.impl_task_buffers,
            .impl_task_images = impl.impl_task_images,
        };

        for (usize task_index = 0; task_index < impl.tasks.size(); ++task_index)
        {
            runtime.execute_task(impl.tasks[task_index], task_index);
        }

        if (!runtime.command_lists.back().is_complete())
        {
            runtime.command_lists.back().complete();
        }

        impl.recorded_command_lists = std::move(runtime.command_lists);
    }

    auto TaskList::command_lists() -> std::vector<CommandList> &
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(impl.compiled, "to retrieve command lists, the list must be compiled and executed first");

        return impl.recorded_command_lists;
    }

    void TaskList::begin_conditional_scope(TaskConditionalInfo const & info)
    {
        auto & impl = *as<ImplTaskList>();

        auto begin_index = impl.tasks.size();
        impl.tasks.push_back({
            .parent_scope_id = impl.record_state.get_current_scope_id(),
            .event_variant = ImplConditionalTaskBegin{
                .info = info,
                .depth = impl.record_state.conditional_depth,
            },
        });
        impl.record_state.conditional_task_indices.push(begin_index);
        ++impl.record_state.conditional_depth;
    }

    void TaskList::end_conditional_scope()
    {
        auto & impl = *as<ImplTaskList>();

        auto begin_index = impl.record_state.conditional_task_indices.top();
        auto end_index = impl.tasks.size();

        auto & begin_task = std::get<ImplConditionalTaskBegin>(impl.tasks[begin_index].event_variant);
        begin_task.end_index = end_index;

        impl.record_state.conditional_task_indices.pop();
        --impl.record_state.conditional_depth;
        impl.tasks.push_back({
            .parent_scope_id = impl.record_state.get_current_scope_id(),
            .event_variant = ImplConditionalTaskEnd{
                .depth = impl.record_state.conditional_depth,
                .begin_index = begin_index,
            },
        });
    }

    auto TaskList::last_access(TaskBufferId buffer) -> Access
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(impl.compiled, "final access only available after compilation");

        return impl.impl_task_buffers[buffer.index].latest_access;
    }

    auto TaskList::last_access(TaskImageId image) -> Access
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(impl.compiled, "final access only available after compilation");

        return impl.impl_task_images[image.index].latest_access;
    }

    auto TaskList::last_layout(TaskImageId image) -> ImageLayout
    {
        auto & impl = *as<ImplTaskList>();
        DAXA_DBG_ASSERT_TRUE_M(impl.compiled, "final layout only available after compilation");

        return impl.impl_task_images[image.index].latest_layout;
    }

    void TaskRuntime::execute_task(TaskEvent & task_event, usize task_index)
    {
        DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "execute task (index: " << task_index << ")");

        // DAXA_ONLY_IF_TASK_LIST_DEBUG(
        //     std::string indent_str = "";
        //     if (task_event.parent_scope_id > 0) {
        //         auto & parent_scope_task = std::get<ImplConditionalTaskBegin>(impl.tasks[task_event.parent_scope_id].event_variant);
        //         for (u64 i = 0; i < parent_scope_task.depth + 1; ++i)
        //         {
        //             indent_str += "    ";
        //         }
        //     });

        if (ImplGenericTask * generic_task = std::get_if<ImplGenericTask>(&task_event.event_variant))
        {
            DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "  executing ImplGenericTask (name: " << generic_task->info.debug_name << ")" << std::endl);

            usize last_command_list_index = command_lists.size() - 1;

            this->pipeline_barriers(generic_task->barriers);
            auto interface = TaskInterface(this, &generic_task->info.resources);
            generic_task->info.task(interface);
            this->reuse_last_command_list = true;

            for (usize i = last_command_list_index; i < command_lists.size() - 1; ++i)
            {
                if (!command_lists[i].is_complete())
                {
                    command_lists[i].complete();
                }
            }

            if (command_lists.back().is_complete())
            {
                command_lists.push_back(this->current_device.create_command_list({.debug_name = std::string("Task Command List ") + std::to_string(command_lists.size())}));
            }
        }
        else if (ImplCreateBufferTask * create_buffer_task = std::get_if<ImplCreateBufferTask>(&task_event.event_variant))
        {
            DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "  executing ImplCreateBufferTask" << std::endl);

            ImplTaskBuffer & impl_task_buffer = this->impl_task_buffers[create_buffer_task->id.index];
            BufferId buffer_id = impl_task_buffer.fetch_callback();
            this->runtime_buffers.push_back(RuntimeTaskBuffer{
                .buffer_id = buffer_id,
            });
        }
        else if (ImplCreateImageTask * create_image_task = std::get_if<ImplCreateImageTask>(&task_event.event_variant))
        {
            DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "  executing ImplCreateImageTask" << std::endl);

            ImplTaskImage & impl_task_image = this->impl_task_images[create_image_task->id.index];
            ImageId image_id = impl_task_image.fetch_callback();
            ImageViewId image_view_id = image_id.default_view();
            auto image_slice = this->current_device.info_image_view(image_view_id).slice;

            if (image_slice != impl_task_image.slice)
            {
                ImageViewInfo image_view_info = this->current_device.info_image_view(image_view_id);
                image_view_info.slice = impl_task_image.slice;

                // TODO(pahrens): This leaks. The view is never destroyed. Make sure the runtime kills it in the end of execution.
                image_view_id = this->current_device.create_image_view(image_view_info);
            }

            this->runtime_images.push_back(RuntimeTaskImage{
                .image_id = image_id,
                .image_view_id = image_view_id,
            });
        }
        else if (ImplConditionalTaskBegin * conditional_begin_task = std::get_if<ImplConditionalTaskBegin>(&task_event.event_variant))
        {
            DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "  executing ImplConditionalTaskBegin" << std::endl);
            bool result = conditional_begin_task->info.condition();
            if (result)
            {
                DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "\033[32mcondition evaluated true, entering..."
                                                       << "\033[0m" << std::endl);
            }
            else
            {
                DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "\033[31mcondition evaluated false, should jump to task " << (conditional_begin_task->end_index + 1) << "\033[0m" << std::endl);
            }
        }
        else if (ImplConditionalTaskEnd * conditional_end_task = std::get_if<ImplConditionalTaskEnd>(&task_event.event_variant))
        {
            DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "  executing ImplConditionalTaskEnd" << std::endl);
        }
    }

    void TaskRuntime::pipeline_barriers(std::vector<TaskPipelineBarrier> const & barriers)
    {
        for (auto const & barrier : barriers)
        {
            // std::cout << "awaited: " << to_string(barrier.awaited_pipeline_access) << "\n";
            // std::cout << "waiting: " << to_string(barrier.waiting_pipeline_access) << "\n";
            if (barrier.image_barrier)
            {
                ImplTaskImage const & task_image = this->impl_task_images[barrier.image_id.index];
                RuntimeTaskImage const & runtime_image = this->runtime_images[barrier.image_id.index];
                // std::cout << "before layout: " << to_string(barrier.before_layout) << "\n";
                // std::cout << " after layout: " << to_string(barrier.after_layout) << "\n";
                // std::cout << " ^ NAME: " << this->current_device.info_image(runtime_image.image_id).debug_name << "\n";

                this->command_lists.back().pipeline_barrier_image_transition({
                    .awaited_pipeline_access = barrier.awaited_pipeline_access,
                    .waiting_pipeline_access = barrier.waiting_pipeline_access,
                    .before_layout = barrier.before_layout,
                    .after_layout = barrier.after_layout,
                    .image_id = runtime_image.image_id,
                    .image_slice = task_image.slice,
                });
            }
            else
            {
                this->command_lists.back().pipeline_barrier({
                    .awaited_pipeline_access = barrier.awaited_pipeline_access,
                    .waiting_pipeline_access = barrier.waiting_pipeline_access,
                });
            }
            // std::cout << std::endl;
        }
    }

    ImplTaskList::ImplTaskList(TaskListInfo const & info)
        : info{info}
    {
    }

    ImplTaskList::~ImplTaskList()
    {
    }

    auto TaskRecordState::get_current_scope_id() -> u64
    {
        if (this->conditional_task_indices.size() == 0)
            return 0;
        return this->conditional_task_indices.top();
    }

    auto ImplTaskList::managed_cleanup() -> bool
    {
        return true;
    }

    auto ImplTaskList::task_image_access_to_layout_access(TaskImageAccess const & access) -> std::tuple<ImageLayout, Access>
    {
        switch (access)
        {
        case TaskImageAccess::NONE: return {ImageLayout::UNDEFINED, {PipelineStageFlagBits::NONE, AccessTypeFlagBits::NONE}};
        case TaskImageAccess::SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::ALL_GRAPHICS | PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::VERTEX_SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::VERTEX_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::TESSELLATION_CONTROL_SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::TESSELLATION_CONTROL_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::TESSELLATION_EVALUATION_SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::TESSELLATION_EVALUATION_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::GEOMETRY_SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::GEOMETRY_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::FRAGMENT_SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::FRAGMENT_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::COMPUTE_SHADER_READ_ONLY: return {ImageLayout::SHADER_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::PipelineStageFlagBits::ALL_GRAPHICS | PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::VERTEX_SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::VERTEX_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::TESSELLATION_CONTROL_SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::TESSELLATION_CONTROL_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::TESSELLATION_EVALUATION_SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::TESSELLATION_EVALUATION_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::GEOMETRY_SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::GEOMETRY_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::FRAGMENT_SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::FRAGMENT_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::COMPUTE_SHADER_WRITE_ONLY: return {ImageLayout::GENERAL, {PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::PipelineStageFlagBits::ALL_GRAPHICS | PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::VERTEX_SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::VERTEX_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::TESSELLATION_CONTROL_SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::TESSELLATION_CONTROL_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::TESSELLATION_EVALUATION_SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::TESSELLATION_EVALUATION_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::GEOMETRY_SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::GEOMETRY_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::FRAGMENT_SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::FRAGMENT_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::COMPUTE_SHADER_READ_WRITE: return {ImageLayout::GENERAL, {PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::TRANSFER_READ: return {ImageLayout::TRANSFER_SRC_OPTIMAL, {PipelineStageFlagBits::TRANSFER, AccessTypeFlagBits::READ}};
        case TaskImageAccess::TRANSFER_WRITE: return {ImageLayout::TRANSFER_DST_OPTIMAL, {PipelineStageFlagBits::TRANSFER, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::COLOR_ATTACHMENT: return {ImageLayout::COLOR_ATTACHMENT_OPTIMAL, {PipelineStageFlagBits::COLOR_ATTACHMENT_OUTPUT, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::DEPTH_ATTACHMENT: return {ImageLayout::DEPTH_ATTACHMENT_OPTIMAL, {PipelineStageFlagBits::EARLY_FRAGMENT_TESTS | PipelineStageFlagBits::LATE_FRAGMENT_TESTS, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::STENCIL_ATTACHMENT: return {ImageLayout::STENCIL_ATTACHMENT_OPTIMAL, {PipelineStageFlagBits::EARLY_FRAGMENT_TESTS | PipelineStageFlagBits::LATE_FRAGMENT_TESTS, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::DEPTH_STENCIL_ATTACHMENT: return {ImageLayout::DEPTH_STENCIL_ATTACHMENT_OPTIMAL, {PipelineStageFlagBits::EARLY_FRAGMENT_TESTS | PipelineStageFlagBits::LATE_FRAGMENT_TESTS, AccessTypeFlagBits::READ_WRITE}};
        case TaskImageAccess::DEPTH_ATTACHMENT_READ_ONLY: return {ImageLayout::DEPTH_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::EARLY_FRAGMENT_TESTS | PipelineStageFlagBits::LATE_FRAGMENT_TESTS, AccessTypeFlagBits::READ}};
        case TaskImageAccess::STENCIL_ATTACHMENT_READ_ONLY: return {ImageLayout::STENCIL_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::EARLY_FRAGMENT_TESTS | PipelineStageFlagBits::LATE_FRAGMENT_TESTS, AccessTypeFlagBits::READ}};
        case TaskImageAccess::DEPTH_STENCIL_ATTACHMENT_READ_ONLY: return {ImageLayout::DEPTH_STENCIL_READ_ONLY_OPTIMAL, {PipelineStageFlagBits::EARLY_FRAGMENT_TESTS | PipelineStageFlagBits::LATE_FRAGMENT_TESTS, AccessTypeFlagBits::READ}};
        case TaskImageAccess::RESOLVE_WRITE: return {ImageLayout::ATTACHMENT_OPTIMAL, {PipelineStageFlagBits::RESOLVE, AccessTypeFlagBits::WRITE}};
        case TaskImageAccess::PRESENT: return {ImageLayout::PRESENT_SRC, {PipelineStageFlagBits::ALL_COMMANDS, AccessTypeFlagBits::READ}};
        default: DAXA_DBG_ASSERT_TRUE_M(false, "unreachable");
        }
        return {};
    }

    auto ImplTaskList::task_buffer_access_to_access(TaskBufferAccess const & access) -> Access
    {
        switch (access)
        {
        case TaskBufferAccess::NONE: return {PipelineStageFlagBits::NONE, AccessTypeFlagBits::NONE};
        case TaskBufferAccess::SHADER_READ_ONLY: return {PipelineStageFlagBits::ALL_GRAPHICS | PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::VERTEX_SHADER_READ_ONLY: return {PipelineStageFlagBits::VERTEX_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::TESSELLATION_CONTROL_SHADER_READ_ONLY: return {PipelineStageFlagBits::TESSELLATION_CONTROL_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::TESSELLATION_EVALUATION_SHADER_READ_ONLY: return {PipelineStageFlagBits::TESSELLATION_EVALUATION_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::GEOMETRY_SHADER_READ_ONLY: return {PipelineStageFlagBits::GEOMETRY_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::FRAGMENT_SHADER_READ_ONLY: return {PipelineStageFlagBits::FRAGMENT_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::COMPUTE_SHADER_READ_ONLY: return {PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::SHADER_WRITE_ONLY: return {PipelineStageFlagBits::PipelineStageFlagBits::ALL_GRAPHICS | PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::VERTEX_SHADER_WRITE_ONLY: return {PipelineStageFlagBits::VERTEX_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::TESSELLATION_CONTROL_SHADER_WRITE_ONLY: return {PipelineStageFlagBits::TESSELLATION_CONTROL_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::TESSELLATION_EVALUATION_SHADER_WRITE_ONLY: return {PipelineStageFlagBits::TESSELLATION_EVALUATION_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::GEOMETRY_SHADER_WRITE_ONLY: return {PipelineStageFlagBits::GEOMETRY_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::FRAGMENT_SHADER_WRITE_ONLY: return {PipelineStageFlagBits::FRAGMENT_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::COMPUTE_SHADER_WRITE_ONLY: return {PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::SHADER_READ_WRITE: return {PipelineStageFlagBits::PipelineStageFlagBits::ALL_GRAPHICS | PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::VERTEX_SHADER_READ_WRITE: return {PipelineStageFlagBits::VERTEX_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::TESSELLATION_CONTROL_SHADER_READ_WRITE: return {PipelineStageFlagBits::TESSELLATION_CONTROL_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::TESSELLATION_EVALUATION_SHADER_READ_WRITE: return {PipelineStageFlagBits::TESSELLATION_EVALUATION_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::GEOMETRY_SHADER_READ_WRITE: return {PipelineStageFlagBits::GEOMETRY_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::FRAGMENT_SHADER_READ_WRITE: return {PipelineStageFlagBits::FRAGMENT_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::COMPUTE_SHADER_READ_WRITE: return {PipelineStageFlagBits::COMPUTE_SHADER, AccessTypeFlagBits::READ_WRITE};
        case TaskBufferAccess::TRANSFER_READ: return {PipelineStageFlagBits::TRANSFER, AccessTypeFlagBits::READ};
        case TaskBufferAccess::TRANSFER_WRITE: return {PipelineStageFlagBits::TRANSFER, AccessTypeFlagBits::WRITE};
        case TaskBufferAccess::HOST_TRANSFER_READ: return {PipelineStageFlagBits::HOST, AccessTypeFlagBits::READ};
        case TaskBufferAccess::HOST_TRANSFER_WRITE: return {PipelineStageFlagBits::HOST, AccessTypeFlagBits::WRITE};
        default: DAXA_DBG_ASSERT_TRUE_M(false, "unreachable");
        }
        return {};
    }

    auto ImplTaskList::compute_needed_barrier(Access const & previous_access, Access const & new_access)
        -> std::optional<TaskPipelineBarrier>
    {
        if (previous_access.type == AccessTypeFlagBits::READ && new_access.type == AccessTypeFlagBits::READ)
        {
            return {};
        }

        return {};
    }

    auto ImplTaskList::slot(TaskBufferId id) -> ImplTaskBuffer &
    {
        DAXA_DBG_ASSERT_TRUE_M(id.index != 0 && id.index <= impl_task_buffers.size(), "incalid task buffer id");
        return impl_task_buffers[id.index - 1];
    }

    auto ImplTaskList::slot(TaskImageId id) -> ImplTaskImage &
    {
        DAXA_DBG_ASSERT_TRUE_M(id.index != 0 && id.index <= impl_task_images.size(), "incalid task image id");
        return impl_task_images[id.index - 1];
    }

    auto ImplTaskList::get_buffer(TaskBufferId) -> BufferId
    {
        return {};
    }

    auto ImplTaskList::get_image(TaskImageId) -> ImageId
    {
        return {};
    }

    auto ImplTaskList::get_image_view(TaskImageId) -> ImageViewId
    {
        return {};
    }

    void ImplTaskList::output_graphviz()
    {
        std::string filename = this->info.debug_name + ".dot";
        std::ofstream dot_file{filename};

        dot_file << "digraph TaskGraph {\nnode [style=filled, shape=box, color=\"#d3f4ff\"]\n";

        for (usize task_index = 0; task_index < this->tasks.size(); ++task_index)
        {
            std::string task_name = std::string("task_") + std::to_string(task_index);
            if (ImplGenericTask * task_ptr =
                    std::get_if<ImplGenericTask>(&tasks[task_index].event_variant))
            {
                dot_file << "subgraph cluster_" << task_name << " {\n";
                dot_file << "label=\"" << task_ptr->info.debug_name << "\"\n";
                dot_file << "shape=box\nstyle=filled\ncolor=lightgray\n";
                for (auto & [task_buffer_id, t_access] : task_ptr->info.resources.buffers)
                {
                    ImplTaskBuffer & task_buffer = this->impl_task_buffers[task_buffer_id.index];
                    auto node_name = task_name + "_res_" + std::to_string(task_buffer_id.index);
                    dot_file << "node_" << task_index << "_" << task_buffer_id.index;
                    dot_file << " [label=\"" << task_buffer.debug_name << "\", shape=box]\n";
                }
                dot_file << "}\n";
            }
            else if (ImplCreateBufferTask * task_ptr =
                         std::get_if<ImplCreateBufferTask>(&tasks[task_index].event_variant))
            {
                ImplTaskBuffer & task_buffer = this->impl_task_buffers[task_ptr->id.index];
                dot_file << "node_" << task_index + 1 << "_" << task_ptr->id.index;
                dot_file << " [label=\"Create " << task_buffer.debug_name << "\", shape=box]\n";
            }
            else if (ImplCreateImageTask * task_ptr =
                         std::get_if<ImplCreateImageTask>(&tasks[task_index].event_variant))
            {
                ImplTaskImage & task_image = this->impl_task_images[task_ptr->id.index];
                dot_file << "node_" << task_index + 1 << "_" << task_ptr->id.index;
                dot_file << " [label=\"Create " << task_image.debug_name << "\", shape=box]\n";
            }
            else if (ImplConditionalTaskBegin * conditional_scope_begin =
                         std::get_if<ImplConditionalTaskBegin>(&tasks[task_index].event_variant))
            {
                auto name = std::string("Conditional") + conditional_scope_begin->info.debug_name;
                dot_file << "subgraph cluster_cond" << task_index << " {\nlabel=\"" << name;
                dot_file << "\"\nshape=box\nstyle=dashed\ncolor=lightgray\n";
            }
            else if (ImplConditionalTaskEnd * conditional_scope_end =
                         std::get_if<ImplConditionalTaskEnd>(&tasks[task_index].event_variant))
            {
                dot_file << "}\n";
            }
            else
            {
                dot_file << "node" << task_index << " [label=\"unknown task\", shape=box]\n";
            }
        }

        for (auto & buffer_link : compiled_graph.buffer_links)
        {
            auto a = buffer_link.event_a;
            auto b = buffer_link.event_b;
            auto i = buffer_link.resource;
            dot_file << "node_" << a << "_" << i << "->node_" << b << "_" << i;
            dot_file << " [label=\"Sync\", labeltooltip=\"between "
                     << to_string(buffer_link.barrier.awaited_pipeline_access.stages) << " "
                     << to_string(buffer_link.barrier.awaited_pipeline_access.type) << " and "
                     << to_string(buffer_link.barrier.waiting_pipeline_access.stages) << " "
                     << to_string(buffer_link.barrier.waiting_pipeline_access.type) << "\"]\n";
        }

        for (auto & image_link : compiled_graph.image_links)
        {
            auto a = image_link.event_a;
            auto b = image_link.event_b;
            auto i = image_link.resource;
            dot_file << "node_" << a << "_" << i << "->node_" << b << "_" << i;
            dot_file << " [label=\"Sync\", labeltooltip=\"between "
                     << to_string(image_link.barrier.awaited_pipeline_access.stages) << " "
                     << to_string(image_link.barrier.awaited_pipeline_access.type) << " and "
                     << to_string(image_link.barrier.waiting_pipeline_access.stages) << " "
                     << to_string(image_link.barrier.waiting_pipeline_access.type) << "\"]\n";
        }

        dot_file << "}\n";
    }

    void ImplTaskList::insert_synchronization()
    {
        DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout << "insert task list" << std::endl);

        usize last_task_index_with_barrier = std::numeric_limits<usize>::max();

        auto insert_sync_for_resources = [&](TaskResources & resources, usize task_index)
        {
            // TODO: Speak with Patrick
            // if (tasks[task_index].parent_scope_id != 0)
            // {
            //     auto & cond_begin_task = std::get<ImplConditionalTaskBegin>(tasks[tasks[task_index].parent_scope_id].event_variant);
            //     // insert resources?
            // }

            for (auto & [task_buffer_id, t_access] : resources.buffers)
            {
                ImplTaskBuffer & task_buffer = this->impl_task_buffers[task_buffer_id.index];

                auto new_access = task_buffer_access_to_access(t_access);
                auto & latest_access = task_buffer.latest_access;

                // When the last access is done by a conditional scope's beginning, we do not need to synchronize on it.
                // This is because it is guaranteed that this access is actually our own, as the conditional scopes beginning is just gatering all out of scope accesses.
                // This also means, that if a barrier is needed, that barrier will be inserted before the conditional scopes beginning, so inserting an additional barrier here would be redundant.
                bool conditional_scope_covers_last_access_barrier = std::holds_alternative<ImplConditionalTaskBegin>(this->tasks[task_buffer.latest_access_task_index].event_variant);

                DAXA_ONLY_IF_TASK_LIST_DEBUG(
                    std::cout
                    << "    task access: buffer tid: "
                    << task_buffer_id.index
                    << ",\n      previous access: "
                    << to_string(task_buffer.latest_access)
                    << ",\n      new access: "
                    << to_string(new_access)
                    << std::endl);

                bool need_memory_barrier = false;
                bool need_execution_barrier = false;

                if (latest_access.type & AccessTypeFlagBits::WRITE)
                {
                    need_memory_barrier = true;
                    need_execution_barrier = true;
                }
                else if ((latest_access.type & AccessTypeFlagBits::READ) != 0 && (new_access.type & AccessTypeFlagBits::WRITE) != 0)
                {
                    need_execution_barrier = true;
                }

                if ((need_memory_barrier || need_execution_barrier) && !conditional_scope_covers_last_access_barrier)
                {
                    usize latest_access_task_index = task_buffer.latest_access_task_index;

                    usize barrier_task_index = {};

                    if (latest_access_task_index >= last_task_index_with_barrier)
                    {
                        // reuse old barrier
                        barrier_task_index = last_task_index_with_barrier;
                    }
                    else
                    {
                        // insert new barrier
                        barrier_task_index = task_index;
                        last_task_index_with_barrier = task_index;
                    }
                    std::get_if<ImplGenericTask>(&tasks[barrier_task_index].event_variant)->barriers.push_back(TaskPipelineBarrier{
                        .image_barrier = false,
                        .awaited_pipeline_access = Access{
                            .stages = latest_access.stages,
                            .type = need_memory_barrier ? latest_access.type : AccessTypeFlagBits::NONE,
                        },
                        .waiting_pipeline_access = Access{
                            .stages = new_access.stages,
                            .type = need_memory_barrier ? new_access.type : AccessTypeFlagBits::NONE,
                        },
                    });

                    compiled_graph.buffer_links.push_back(TaskLink{
                        .event_a = latest_access_task_index,
                        .event_b = task_index,
                        .resource = task_buffer_id.index,
                        .barrier = TaskPipelineBarrier{
                            .image_barrier = false,
                            .awaited_pipeline_access = Access{
                                .stages = latest_access.stages,
                                .type = need_memory_barrier ? latest_access.type : AccessTypeFlagBits::NONE,
                            },
                            .waiting_pipeline_access = Access{
                                .stages = new_access.stages,
                                .type = need_memory_barrier ? new_access.type : AccessTypeFlagBits::NONE,
                            },
                        },
                    });

                    latest_access = new_access;
                }
                else
                {
                    latest_access = latest_access | new_access;
                }
                task_buffer.latest_access_task_index = task_index;
            }

            for (auto & [task_image_id, t_access] : resources.images)
            {
                ImplTaskImage & task_image = this->impl_task_images[task_image_id.index];

                auto [new_layout, new_access] = task_image_access_to_layout_access(t_access);
                auto & latest_layout = task_image.latest_layout;
                auto & latest_access = task_image.latest_access;

                // When the last access is done by a conditional scope's beginning, we do not need to synchronize on it.
                // This is because it is guaranteed that this access is actually our own, as the conditional scopes beginning is just gatering all out of scope accesses.
                // This also means, that if a barrier is needed, that barrier will be inserted before the conditional scopes beginning, so inserting an additional barrier here would be redundant.
                bool conditional_scope_covers_last_access_barrier = std::holds_alternative<ImplConditionalTaskBegin>(this->tasks[task_image.latest_access_task_index].event_variant);

                DAXA_ONLY_IF_TASK_LIST_DEBUG(
                    std::cout
                    << "    task access: image task_image_id: "
                    << task_image_id.index
                    << ", name: "
                    << impl_task_images[task_image_id.index].debug_name
                    << ",\n      previous access: "
                    << to_string(task_image.latest_access)
                    << ",\n      previous layout: "
                    << to_string(task_image.latest_layout)
                    << ",\n      new access: "
                    << to_string(new_access)
                    << ",\n      new layout: "
                    << to_string(new_layout)
                    << std::endl);

                bool need_memory_barrier = false;
                bool need_execution_barrier = false;

                if (latest_access.type & AccessTypeFlagBits::WRITE)
                {
                    need_memory_barrier = true;
                    need_execution_barrier = true;
                }
                else if ((latest_access.type & AccessTypeFlagBits::READ) != 0 && (new_access.type & AccessTypeFlagBits::WRITE) != 0)
                {
                    need_execution_barrier = true;
                }

                bool need_layout_transition = new_layout != latest_layout;

                need_memory_barrier |= need_layout_transition;
                need_execution_barrier |= need_layout_transition;

                if ((need_memory_barrier || need_execution_barrier || need_layout_transition) && !conditional_scope_covers_last_access_barrier)
                {
                    usize latest_access_task_index = task_image.latest_access_task_index;

                    usize barrier_task_index = {};

                    if (last_task_index_with_barrier != std::numeric_limits<usize>::max() && latest_access_task_index < last_task_index_with_barrier)
                    {
                        // reuse old barrier
                        barrier_task_index = last_task_index_with_barrier;
                    }
                    else
                    {
                        // insert new barrier
                        barrier_task_index = task_index;
                        last_task_index_with_barrier = task_index;
                    }
                    std::get_if<ImplGenericTask>(&tasks[barrier_task_index].event_variant)->barriers.push_back(TaskPipelineBarrier{
                        .image_barrier = true,
                        .awaited_pipeline_access = Access{
                            .stages = latest_access.stages,
                            .type = need_memory_barrier ? latest_access.type : AccessTypeFlagBits::NONE,
                        },
                        .waiting_pipeline_access = Access{
                            .stages = new_access.stages,
                            .type = need_memory_barrier ? new_access.type : AccessTypeFlagBits::NONE,
                        },
                        .before_layout = latest_layout,
                        .after_layout = new_layout,
                        .image_id = task_image_id,
                        .image_slice = task_image.slice,
                    });
                    compiled_graph.image_links.push_back(TaskLink{
                        .event_a = latest_access_task_index,
                        .event_b = task_index,
                        .resource = task_image_id.index,
                        .barrier = TaskPipelineBarrier{
                            .image_barrier = true,
                            .awaited_pipeline_access = Access{
                                .stages = latest_access.stages,
                                .type = need_memory_barrier ? latest_access.type : AccessTypeFlagBits::NONE,
                            },
                            .waiting_pipeline_access = Access{
                                .stages = new_access.stages,
                                .type = need_memory_barrier ? new_access.type : AccessTypeFlagBits::NONE,
                            },
                            .before_layout = latest_layout,
                            .after_layout = new_layout,
                            .image_id = task_image_id,
                            .image_slice = task_image.slice,
                        },
                    });

                    DAXA_ONLY_IF_TASK_LIST_DEBUG(
                        std::cout
                        << "    inserted barrier at task index: "
                        << barrier_task_index
                        << ",\n      task image index: "
                        << task_image_id.index
                        << ", name: "
                        << impl_task_images[task_image_id.index].debug_name
                        << ",\n      awaited_pipeline_access: "
                        << to_string(std::get_if<ImplGenericTask>(&tasks[barrier_task_index].event_variant)->barriers.back().awaited_pipeline_access)
                        << ",\n      waiting_pipeline_access: "
                        << to_string(std::get_if<ImplGenericTask>(&tasks[barrier_task_index].event_variant)->barriers.back().waiting_pipeline_access)
                        << ",\n      before_layout: "
                        << to_string(latest_layout)
                        << ",\n      after_layout: "
                        << to_string(new_layout)
                        << std::endl);

                    latest_layout = new_layout;
                    latest_access = new_access;
                }
                else
                {
                    latest_access = latest_access | new_access;
                }
                task_image.latest_access_task_index = task_index;
            }
        };

        for (usize task_index = 0; task_index < this->tasks.size(); ++task_index)
        {
            if (ImplGenericTask * task_ptr = std::get_if<ImplGenericTask>(&tasks[task_index].event_variant))
            {
                DAXA_ONLY_IF_TASK_LIST_DEBUG(
                    std::cout
                    << "  process task index : "
                    << task_index
                    << ", name: "
                    << task_ptr->info.debug_name
                    << "\n  {"
                    << std::endl);

                insert_sync_for_resources(task_ptr->info.resources, task_index);

                DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout
                                             << "  }\n"
                                             << std::endl);
            }
            // if (ImplConditionalTaskBegin * conditional_scope_begin = std::get_if<ImplConditionalTaskBegin>(&tasks[task_index].event_variant))
            // {
            //     DAXA_ONLY_IF_TASK_LIST_DEBUG(
            //         std::cout
            //         << "  process conditional scope index : "
            //         << task_index
            //         << ", name: "
            //         << conditional_scope_begin->info.debug_name
            //         << "\n  {"
            //         << std::endl);
            //     insert_sync_for_resources(conditional_scope_begin->resources, task_index);
            //     DAXA_ONLY_IF_TASK_LIST_DEBUG(std::cout
            //                                  << "  }\n"
            //                                  << std::endl);
            // }
        }
    }
} // namespace daxa

#endif