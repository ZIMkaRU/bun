/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "ReadableStreamDefaultReaderBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/ImplementationVisibility.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_readableStreamDefaultReaderInitializeReadableStreamDefaultReaderCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamDefaultReaderInitializeReadableStreamDefaultReaderCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamDefaultReaderInitializeReadableStreamDefaultReaderCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamDefaultReaderInitializeReadableStreamDefaultReaderCodeLength = 393;
static const JSC::Intrinsic s_readableStreamDefaultReaderInitializeReadableStreamDefaultReaderCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamDefaultReaderInitializeReadableStreamDefaultReaderCode =
    "(function (stream)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStream(stream))\n" \
    "        @throwTypeError(\"ReadableStreamDefaultReader needs a ReadableStream\");\n" \
    "    if (@isReadableStreamLocked(stream))\n" \
    "        @throwTypeError(\"ReadableStream is locked\");\n" \
    "\n" \
    "    @readableStreamReaderGenericInitialize(this, stream);\n" \
    "    @putByIdDirectPrivate(this, \"readRequests\", @createFIFO());\n" \
    "\n" \
    "    return this;\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamDefaultReaderCancelCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamDefaultReaderCancelCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamDefaultReaderCancelCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamDefaultReaderCancelCodeLength = 416;
static const JSC::Intrinsic s_readableStreamDefaultReaderCancelCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamDefaultReaderCancelCode =
    "(function (reason)\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamDefaultReader(this))\n" \
    "        return @Promise.@reject(@makeThisTypeError(\"ReadableStreamDefaultReader\", \"cancel\"));\n" \
    "\n" \
    "    if (!@getByIdDirectPrivate(this, \"ownerReadableStream\"))\n" \
    "        return @Promise.@reject(@makeTypeError(\"cancel() called on a reader owned by no readable stream\"));\n" \
    "\n" \
    "    return @readableStreamReaderGenericCancel(this, reason);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamDefaultReaderReadManyCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamDefaultReaderReadManyCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamDefaultReaderReadManyCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamDefaultReaderReadManyCodeLength = 3712;
static const JSC::Intrinsic s_readableStreamDefaultReaderReadManyCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamDefaultReaderReadManyCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamDefaultReader(this))\n" \
    "        @throwTypeError(\"ReadableStreamDefaultReader.readMany() should not be called directly\");\n" \
    "\n" \
    "    const stream = @getByIdDirectPrivate(this, \"ownerReadableStream\");\n" \
    "    if (!stream)\n" \
    "        @throwTypeError(\"readMany() called on a reader owned by no readable stream\");\n" \
    "\n" \
    "    const state = @getByIdDirectPrivate(stream, \"state\");\n" \
    "    @putByIdDirectPrivate(stream, \"disturbed\", true);\n" \
    "    if (state === @streamClosed)\n" \
    "        return {value: [], size: 0, done: true};\n" \
    "    else if (state === @streamErrored) {\n" \
    "        throw @getByIdDirectPrivate(stream, \"storedError\");\n" \
    "    }\n" \
    "\n" \
    "    \n" \
    "    var controller = @getByIdDirectPrivate(stream, \"readableStreamController\");\n" \
    "\n" \
    "    const content = @getByIdDirectPrivate(controller, \"queue\").content;\n" \
    "    var size = @getByIdDirectPrivate(controller, \"queue\").size;\n" \
    "    var values = content.toArray(false);\n" \
    "    var length = values.length;\n" \
    "\n" \
    "    if (length > 0) {\n" \
    "\n" \
    "        if (@isReadableByteStreamController(controller)) {\n" \
    "            for (var i = 0; i < value.length; i++) {\n" \
    "                const buf = value[i];\n" \
    "                if (!(@ArrayBuffer.@isView(buf) || buf instanceof @ArrayBuffer)) {\n" \
    "                    value[i] = new @Uint8Array(buf.buffer, buf.byteOffset, buf.byteLength);\n" \
    "                }\n" \
    "            }\n" \
    "        } else {\n" \
    "            values[0] = values[0].value;\n" \
    "            for (var i = 1; i < values.length; i++) {\n" \
    "                values[i] = values[i].value;\n" \
    "            }\n" \
    "        }\n" \
    "        \n" \
    "        @resetQueue(@getByIdDirectPrivate(controller, \"queue\"));\n" \
    "\n" \
    "        if (@getByIdDirectPrivate(controller, \"closeRequested\"))\n" \
    "            @readableStreamClose(@getByIdDirectPrivate(controller, \"controlledReadableStream\"));\n" \
    "        else if (@isReadableStreamDefaultController(controller)) \n" \
    "            @readableStreamDefaultControllerCallPullIfNeeded(controller);\n" \
    "        else if (@isReadableByteStreamController(controller))\n" \
    "            @readableByteStreamControllerCallPullIfNeeded(controller);\n" \
    "\n" \
    "        return {value: values, size, done: false};\n" \
    "    }\n" \
    "\n" \
    "    var onPullMany = (result) => {\n" \
    "        if (result.done) {\n" \
    "            return {value: [], size: 0, done: true};\n" \
    "        }\n" \
    "        var controller = @getByIdDirectPrivate(stream, \"readableStreamController\");\n" \
    "        \n" \
    "        var queue = @getByIdDirectPrivate(controller, \"queue\");\n" \
    "        var value = [result.value].concat(queue.content.toArray(false));\n" \
    "\n" \
    "        if (@isReadableByteStreamController(controller)) {\n" \
    "            for (var i = 0; i < value.length; i++) {\n" \
    "                const buf = value[i];\n" \
    "                if (!(@ArrayBuffer.@isView(buf) || buf instanceof @ArrayBuffer)) {\n" \
    "                    value[i] = new @Uint8Array(buf.buffer, buf.byteOffset, buf.byteLength);\n" \
    "                }\n" \
    "            }\n" \
    "        } else {\n" \
    "            for (var i = 1; i < value.length; i++) {\n" \
    "                value[i] = value[i].value;\n" \
    "            }\n" \
    "        }\n" \
    "        \n" \
    "        var size = queue.size;\n" \
    "        @resetQueue(queue);\n" \
    "\n" \
    "        if (@getByIdDirectPrivate(controller, \"closeRequested\"))\n" \
    "            @readableStreamClose(@getByIdDirectPrivate(controller, \"controlledReadableStream\"));\n" \
    "        else if (@isReadableStreamDefaultController(controller)) \n" \
    "            @readableStreamDefaultControllerCallPullIfNeeded(controller);\n" \
    "        else if (@isReadableByteStreamController(controller))\n" \
    "            @readableByteStreamControllerCallPullIfNeeded(controller);\n" \
    "        \n" \
    "\n" \
    "        \n" \
    "        return {value: value, size: size, done: false};\n" \
    "    };\n" \
    "    \n" \
    "    var pullResult = controller.@pull(controller);\n" \
    "    if (pullResult && @isPromise(pullResult)) {\n" \
    "        return pullResult.@then(onPullMany);\n" \
    "    }\n" \
    "\n" \
    "    return onPullMany(pullResult);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamDefaultReaderReadCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamDefaultReaderReadCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamDefaultReaderReadCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamDefaultReaderReadCodeLength = 395;
static const JSC::Intrinsic s_readableStreamDefaultReaderReadCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamDefaultReaderReadCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamDefaultReader(this))\n" \
    "        return @Promise.@reject(@makeThisTypeError(\"ReadableStreamDefaultReader\", \"read\"));\n" \
    "    if (!@getByIdDirectPrivate(this, \"ownerReadableStream\"))\n" \
    "        return @Promise.@reject(@makeTypeError(\"read() called on a reader owned by no readable stream\"));\n" \
    "\n" \
    "    return @readableStreamDefaultReaderRead(this);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamDefaultReaderReleaseLockCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamDefaultReaderReleaseLockCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamDefaultReaderReleaseLockCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamDefaultReaderReleaseLockCodeLength = 449;
static const JSC::Intrinsic s_readableStreamDefaultReaderReleaseLockCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamDefaultReaderReleaseLockCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamDefaultReader(this))\n" \
    "        throw @makeThisTypeError(\"ReadableStreamDefaultReader\", \"releaseLock\");\n" \
    "\n" \
    "    if (!@getByIdDirectPrivate(this, \"ownerReadableStream\"))\n" \
    "        return;\n" \
    "\n" \
    "    if (@getByIdDirectPrivate(this, \"readRequests\")?.isNotEmpty())\n" \
    "        @throwTypeError(\"There are still pending read requests, cannot release the lock\");\n" \
    "\n" \
    "    @readableStreamReaderGenericRelease(this);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_readableStreamDefaultReaderClosedCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_readableStreamDefaultReaderClosedCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_readableStreamDefaultReaderClosedCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_readableStreamDefaultReaderClosedCodeLength = 257;
static const JSC::Intrinsic s_readableStreamDefaultReaderClosedCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_readableStreamDefaultReaderClosedCode =
    "(function ()\n" \
    "{\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    if (!@isReadableStreamDefaultReader(this))\n" \
    "        return @Promise.@reject(@makeGetterTypeError(\"ReadableStreamDefaultReader\", \"closed\"));\n" \
    "\n" \
    "    return @getByIdDirectPrivate(this, \"closedPromiseCapability\").@promise;\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().readableStreamDefaultReaderBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().readableStreamDefaultReaderBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_READABLESTREAMDEFAULTREADER_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
