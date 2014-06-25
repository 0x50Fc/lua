
PLAY_UP = 1;
PLAY_DOWN = 2;
PLAY_LEFT = 3;
PLAY_RIGHT = 4;
PLAY_RUN = 5;

root = E("GLSceneElement")
    :add(
        E("GLCanvasElement")
        :call("setPosition",0.5,0.2,0)
        :add(
            E("GLRoleElement","role")
            :call("setStatus",PLAY_RIGHT)
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_DOWN)
                :setValue("enabledStatus",PLAY_RUN)
                :setValue("defaultIndex",0)
                :setValue("duration",0.6)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0,0,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.25,0,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.5,0,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.75,0,0.25,0.25)
                    :setValue("uri","ma.png")
                )
            )
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_LEFT)
                :setValue("enabledStatus",PLAY_RUN)
                :setValue("defaultIndex",3)
                :setValue("duration",0.6)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0,0.25,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.25,0.25,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.5,0.25,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.75,0.25,0.25,0.25)
                    :setValue("uri","ma.png")
                )
            )
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_RIGHT)
                :setValue("enabledStatus",PLAY_RUN)
                :setValue("defaultIndex",3)
                :setValue("duration",0.6)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0,0.5,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.25,0.5,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.5,0.5,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.75,0.5,0.25,0.25)
                    :setValue("uri","ma.png")
                )
            )
            :add(
                E("GLTacticFramesElement")
                :setValue("visableStatus",PLAY_UP)
                :setValue("enabledStatus",PLAY_RUN)
                :setValue("defaultIndex",0)
                :setValue("duration",0.6)
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0,0.75,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.25,0.75,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.5,0.75,0.25,0.25)
                    :setValue("uri","ma.png")
                )
                :add(
                    E("GLSpriteElement")
                    :call("setSize",80,100)
                    :call("setRect",0.75,0.75,0.25,0.25)
                    :setValue("uri","ma.png")
                )
            )
        )
    )
    :add(
        E("GLScreenElement")
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
        
        if x == 0 and y == 0 then
            
            E("#role"):call("removeStatus",PLAY_RUN);

        else
        
            if dx > dy then
                if x > 0 then
                    E("#role"):call("setStatus",PLAY_RIGHT,PLAY_RUN);
                end
                if x < 0 then
                    E("#role"):call("setStatus",PLAY_LEFT,PLAY_RUN);
                end
            end
            
            if dy > dx then
                if y > 0 then
                    E("#role"):call("setStatus",PLAY_DOWN,PLAY_RUN);
                end
                if y < 0 then
                    E("#role"):call("setStatus",PLAY_UP,PLAY_RUN);
                end
            end

        end



    end
end