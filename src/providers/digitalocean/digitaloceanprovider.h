/*
MIT License

Copyright (c) 2022 Pedro Nunes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "providers/provider.h"
#include "webclient/webclient.h"

namespace Turbine
{

class DigitalOceanProvider;
using DigitalOceanProviderUniquePtr = std::unique_ptr<DigitalOceanProvider>;

class DigitalOceanProvider : public Provider
{
public:
	DigitalOceanProvider();
	virtual ~DigitalOceanProvider() override;

	virtual void Update(float delta) override;

	virtual const std::string& GetName() const override;
	virtual bool IsAuthenticated() const override;
	virtual void CreateBridge(const std::string& name, bool isPublic) override;

private:
	bool HasAPIKeyChanged();
	void TryAuthenticate();
	void RebuildHeaders();

	std::string m_Name;
	std::string m_APIKey;
	bool m_Authenticated;
	bool m_AuthenticationInFlight;
	WebClient::Headers m_Headers;
};

} // namespace Turbine
