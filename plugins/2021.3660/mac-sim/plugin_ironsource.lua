
local Library = require "CoronaLibrary"

-- Create library
local lib = Library:new{ name="plugin.ironsource", publisherId="com.cabagomez", version=1 }

-------------------------------------------------------------------------------
-- BEGIN
-------------------------------------------------------------------------------

-- This sample implements the following Lua:
-- 
--    local ironsource = require "plugin.ironsource"
--    ironsource.init()
--    

local function showWarning(functionName)
    print( functionName .. " WARNING: The ironsource plugin is only supported on iOS and Android. Please build for device")
end

function lib.init()
    showWarning("ironsource.init()")
end

function lib.show()
    showWarning("ironsource.show()")
end

function lib.isAvailable()
    showWarning("ironsource.isAvailable()")
end

function lib.hide()
    showWarning("ironsource.hide()")
end

function lib.load()
    showWarning("ironsource.load()")
end

-------------------------------------------------------------------------------
-- END
-------------------------------------------------------------------------------

-- Return an instance
return lib
