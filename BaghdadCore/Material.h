#pragma once

#include <memory>
#include <wrl/client.h>

#include "PixelShader.h"
#include "VertexShader.h"
#include "ShaderReflectionDB.h"
#include "ShaderModule.h"

#include "Device.h"
#include "DeviceContext.h"

namespace BaghdadCore
{
	class Material final
	{
		friend class MaterialBuilder;
		friend class Renderer;
		
	private:
		void Bind(const Device& device, const DeviceContext& context) const noexcept(!_DEBUG);

		Material(VertexShader&& vertexShader, PixelShader&& pixelShader, 
			ShaderModule&& vertexModule,
			ShaderReflectionDB&& vertexReflectionDB, ShaderReflectionDB&& pixelReflectionDB,
			Microsoft::WRL::ComPtr<ID3D11InputLayout>&& pInputLayout);

	private:
		VertexShader _vertexShader;
		PixelShader _pixelShader;
		ShaderModule _vertexModule;
		ShaderReflectionDB _pixelReflectionDB;
		ShaderReflectionDB _vertexReflectionDB;

		Microsoft::WRL::ComPtr<ID3D11InputLayout> _pInputLayout;
	};
}

