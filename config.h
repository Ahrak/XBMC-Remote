#ifndef CONFIG_H
#define CONFIG_H

#include "QString"

/**
 * Config Object
 */
struct Config
{
    Config()
        : host("192.168.1.173")
        , port(8080)
    {
        //
    }

    /** xbmc host */
    QString host;

    /** port number */
    int port;

};


class XBMCRemoteConfig
{
    public:

        static XBMCRemoteConfig& instance();

        Config config() const
        {
            return m_config;
        }


        void setHost(QString host)
        {
            m_config.host = host;
        }


        void setPort(int port)
        {
            if(port <= 1023  || port > 65535)
            {
                port = 8080;
            }
            m_config.port = port;
        }

        ~XBMCRemoteConfig(){};

    protected:

        XBMCRemoteConfig(){};


    private:


        Config m_config;


};

#endif // CONFIG_H
