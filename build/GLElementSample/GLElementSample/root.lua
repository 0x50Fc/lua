
PLAY_LEFT = 1;
PLAY_RIGHT = 2;
PLAY_LEFT_RUN = 3;
PLAY_RIGHT_RUN = 4;

root = E("SKSceneElement")
    :call("setMapSize",1400,325)
    :call("setPlayMapPosition",120,220,10)
    :add(
        E("SKMapLayerElement")
        :setValue("background-uri","map.jpg")
    )
    :add(
        E("GLSpriteElement")
        :add(
            E("SKPlayerElement")
            :call("setStatus",PLAY_RIGHT)
            :setValue("moveSpeed",200)
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_LEFT)
                :setValue("duration",0.8)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-1.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-2.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-3.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-4.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-5.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-6.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-7.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_13-8.png")
                )
            )
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_RIGHT)
                :setValue("duration",0.8)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-1.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-2.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-3.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-4.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-5.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-6.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-7.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",45,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_14-8.png")
                )
            )
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_LEFT_RUN)
                :setValue("duration",0.6)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-1.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-2.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-3.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-4.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-5.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-6.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-7.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_21-8.png")
                )
            )
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_RIGHT_RUN)
                :setValue("duration",0.6)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-1.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-2.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-3.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-4.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-5.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-6.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-7.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",60,75)
                    :call("setAnchor",0.5,1.0)
                    :setValue("uri","npc_25-8.png")
                )
            )
        )
    )
    :add(
        E("GLScreenElement")
        :setValue("zPosition",9000)
        :add(
            E("GLGamepadElement")
            :add(
                E("GLLayerElement")
                :setValue("background-color","#00ff00")
                :setValue("name","begin")
                :setValue("alpha",0.4)
                :call("setSize",44,44)
            )
            :add(
                E("GLLayerElement")
                :setValue("background-color","#ff0000")
                :setValue("name","to")
                :setValue("alpha",0.6)
                :call("setSize",22,22)
            )
            :add(
                E("GLLayerElement")
                :setValue("name","buttons")
                :call("setSize",152,44)
                :add(
                    E("GLGamepadButtonElement")
                    :setValue("background-color","#ff0000")
                    :setValue("alpha",0.6)
                    :setValue("name","A")
                    :call("setFrame",0,0,44,44)
                )
                :add(
                    E("GLGamepadButtonElement")
                    :setValue("background-color","#00ff00")
                    :setValue("alpha",0.6)
                    :setValue("name","B")
                    :call("setFrame",54,0,44,44)
                )
                :add(
                    E("GLGamepadButtonElement")
                    :setValue("background-color","#0000ff")
                    :setValue("alpha",0.6)
                    :setValue("name","C")
                    :call("setFrame",108,0,44,44)
                )
            )
        )
    );

function root:doAction(object)

    local action = O(object);

    local actionType = action:value("actionType");

    if actionType == 1 then

        local x = action:value("x");
        local y = action:value("y");
        local dx = math.abs(x);
        local dy = math.abs(y);

        local player = E(root:elementOfClass("SKPlayerElement"));

        if x == 0 and y == 0 then

            if player:pcall("hasStatus",PLAY_LEFT_RUN) then
                player:call("setStatus",PLAY_LEFT);
            elseif player:pcall("hasStatus",PLAY_RIGHT_RUN) then
                player:call("setStatus",PLAY_RIGHT);
            end

        else

            if x > 0 then
                player:call("setStatus",PLAY_RIGHT_RUN);
            end
            if x < 0 then
                player:call("setStatus",PLAY_LEFT_RUN);
            end

        end



    end
end