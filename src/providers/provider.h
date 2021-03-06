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

#include <list>
#include <memory>
#include <string>

namespace Turbine
{

class Bridge;
class Provider;
using ProviderUniquePtr = std::unique_ptr<Provider>;
using BridgeList = std::list<Bridge*>;

class Provider
{
public:
	Provider() {}
	virtual ~Provider() {}

	virtual void Update(float delta) = 0;
	virtual void RenderSettings() = 0;

	virtual const std::string& GetName() const = 0;
	virtual bool IsAuthenticated() const = 0;
	virtual void CreateBridge(const std::string& name, bool isListed) = 0;
	virtual void OnBridgeDeployed(Bridge* pBridge) = 0;

protected:
	void GetRandomTorPorts(int& orPort, int& extPort) const;

private:
	int GetRandomPort() const;
};

} // namespace Turbine
